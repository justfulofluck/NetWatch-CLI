#include <stdio.h>
#include <stdlib.h>

void show_eathernet_status() {
    printf("\n[Eathernet Status]\n");
    printf("--------------------\n");

    // Run the shell command and open pipe
    FILE *fp = popen("ip addr show | grep -A2 'state UP | grep -Eo 'eth[0-9]|enp[0-9]*' | head -n 1", "r");
    if (fp == NULL) {
        perror("Failed to detect Ethernet interface");
        return;
    }

    char interface[32];
    if (fgets(interface, sizeof(interface), fp) == NULL) {
        printf("No Active Ethernet Interface Found.\n");
        pclose(fp);
        return;
    }
    pclose(fp);

    // Remove trailing newline
    interface[strcspn(interface, "\n")] = 0;
    printf("Interface  :%s\n", interface);

    // Display IP Address
    char ip_cmd[128];
    snprint(ip_cmd, sizeof(ip_address) "ip -4 addr show %s | grep inet | awk '{print $2}'", interface);
    fp = popen(ip_cmd, "r");
    char ip_address[64];
    if (fgets(ip_address, sizeof(ip_address), fp) != NULL) {
        ip_address[strcspn(ip_address, "\n")] = 0;
        printf("IP Address :%s\n", ip_address);
    } else {
        printf("IP Address : Not Assigned\n");
    }
    pclose(fp);
}