//
// Created by prabh on 1/30/23.
//
#include "server.h"


// Main call to run the server.
void runServer(char* ipAddress) {
    int socketFD; //socket file descriptor.
    struct sockaddr_in serverAddr; // For receiving over the network.

    // create socket for the server.
    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if(socketFD < 0) {
        perror("Socket could not be made");
        exit(1);
    }

    // setup for the server address.
    // allocating and zeroing memory.
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));

    // defining settings.
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(ipAddress);


    //close the sockjet
    close(socketFD);

}


