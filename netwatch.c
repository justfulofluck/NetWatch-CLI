#include <stdio.h>
#include <string.h>

// Function declarations
void show_help();



int main(int argc, char *argv[]) {
    if (argc < 2) {
        show_help();
        return 1;
    }

    if (strcmp(argv[1], "-ec")==0) {
        // nw -ec
    } else if (strcmp(argv[1], "-pc")==0) {
        // nw -pc
    } else if (strcmp(argv[1], "status")==0) {
        // nw status
    } else {
        printf("UnKnown Command: %s\n", argv[1]);
        show_help();
    }

    return 0;
}


void show_help() {
    printf("NetWatch CLI - Usage Guide\n");
    printf("-------------------------------\n");
    printf("nw -ec                          # List Ethernet interfaces\n");
    printf("nw -ec control <iface> <on|off># Control Ethernet (up/down)\n");
    printf("nw -pc                          # List active ports\n");
    printf("nw -pc control <port> <on|off> # Control port access\n");
    printf("nw status                      # Show Ethernet status\n");
}

