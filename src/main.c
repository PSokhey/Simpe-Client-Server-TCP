#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{

    if (argv[1] == NULL) {
        fprintf(stderr, "Error: first argument MUST be 'client' or 'server'.\n");
        return 1;
    }

    // check if specified client or server first.
    if(strcmp(argv[1], "server") != 0 && strcmp(argv[1], "client") != 0) {
        perror("Must be server or client\n");
        return 1;
    }
    return 0;
}
