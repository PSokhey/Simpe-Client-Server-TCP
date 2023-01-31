#include <stdio.h>
#include <string.h>
#include "server.h"

int main(int argc, char *argv[])
{

    // Check to see if the first argument is null.
    if (argv[1] == NULL) {
        fprintf(stderr, "Error: first argument MUST be 'client' or 'server'.\n");
        return 1;
    }

    // check if the program should run as a client or server.
    if(strcmp(argv[1], "server") != 0 && strcmp(argv[1], "client") != 0) {
        perror("Must be server or client\n");
        return 1;
    }

    // Check if the client has enough arguments to run.
    if(strcmp(argv[1], "client") == 0 && argc == 4)
    {
    //TODO: IMPLIMENT CLIENT CODE.
    printf("client ran");
    }

    // Chec if the server has enough arguments to run.
    else if(strcmp(argv[1], "server") == 0 && argc == 3)
    {
        //TODO: IMPLIMENT SERVER CODE.
        printf("server ran");
        runServer(argv[2]);
    }
    else {
        perror("Client MUST have the file to read and Ip of server.\n");
        return 1;

    }


    return 0;
}
