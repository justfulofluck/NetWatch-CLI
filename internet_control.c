#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_ethernet_interfaces() {
    printf("Available Ethernet Interfaces:\n");
    printf("-------------------------------\n");

    FILE *fp = popen("ls /sys/class/net | grep -E 'eth|enp|eno' | xargs -n1", "r");
    if (fp == NULL) {
        printf("Error: Failed to list Ethernet interfaces\n");
        return;
    }

    char iface[32];
    while (fgets(iface, sizeof(iface), fp) != NULL) {
        printf("%s", iface);
    }
    pclose(fp);
}

void control_internet(const char *interface, const char *state) {
    char cmd[128];

    if (strcmp(state, "off") == 0) {
        snprintf(cmd, sizeof(cmd), "ip link set %s down", interface);
        int res = system(cmd);
        if (res == 0) {
            printf("Internet connection on %s has been disabled\n", interface);
        } else {
            printf("Error: Failed to disable internet connection on %s\n", interface);
        }
    } else if (strcmp(state, "on") == 0) {
        snprintf(cmd, sizeof(cmd), "ip link set %s up", interface);
        int res = system(cmd);
        if (res == 0) {
            printf("Internet connection on %s has been enabled\n", interface);
        } else {
            printf("Error: Failed to enable internet connection on %s\n", interface);
        }
    } else {
        printf("Error: Invalid state '%s'. Use 'on' or 'off'.\n", state);
    }
}

void handle_internet_control(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "-ec") == 0) {
        list_ethernet_interfaces();
    } else if (argc == 5 && strcmp(argv[1], "-ec") == 0 && strcmp(argv[2], "control") == 0) {
        const char *interface = argv[3];
        const char *state = argv[4];
        control_internet(interface, state);
    } else {
        printf("Usage:\n");
        printf("  nm -ec                         # List Ethernet interfaces\n");
        printf("  nm -ec control <iface> <on|off>  # Control internet on interface\n");
    }
}
