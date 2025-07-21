#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_open_port() {
    printf("Available Open Ports\n");
    printf("------------------------------\n");

    FILE *fp = popen("ss -tulnp | grep LISTEN", "r");
    if (fp == NULL) {
        printf("Error: Failed to list open ports\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    pclose(fp);
}

void control_port(const char *port, const char *state) {
    char cmd[128];

    if (strcmp(state, "off") == 0) {
        snprintf(cmd, sizeof(cmd), "iptables -A INPUT -p tcp --dport %s -j DROP", port);
        int res = system(cmd);
        if (res == 0) {
            printf("Port %s has been disabled\n", port);
        } else {
            printf("Error: Failed to disable port %s\n", port);
        }
    } else if (strcmp(state, "on") == 0) {
        snprintf(cmd, sizeof(cmd), "iptables -D INPUT -p tcp --dport %s -j DROP", port);
        int res = system(cmd);
        if (res == 0) {
            printf("Port %s has been enabled\n", port);
        } else {
            printf("Error: Failed to enable port %s\n", port);
        }
    } else {
        printf("Error: Invalid state '%s'. Use 'on' or 'off'.\n", state);
    }
}

void handle_port_control(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "-pc") == 0) {
        list_open_port();
    } else if (argc == 5 && strcmp(argv[1], "-pc") == 0 && strcmp(argv[2], "control") == 0) {
        const char *port = argv[3];
        const char *state = argv[4];
        control_port(port, state);
    } else {
        printf("Usage:\n");
        printf("  nw -pc                        # Show open ports\n");
        printf("  nw -pc control <port> <on|off>  # Toggle port access\n");
    }
}
