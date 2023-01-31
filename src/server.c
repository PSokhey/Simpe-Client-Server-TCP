//
// Created by prabh on 1/30/23.
//
#include "server.h"


// Main call to run the server.
void runServer(char* ipAddress) {
    int socketServer, socketClient; //socket file descriptor.
    struct sockaddr_in serverAddr, clientAddr; // For receiving over the network.
    socklen_t clientLength = sizeof (struct sockaddr_in);


    // create socket for the server.
    socketServer = socket(AF_INET, SOCK_STREAM, 0);
    if(socketServer < 0) {
        perror("Socket could not be made");
        exit(1);
    }

    // setup for the server address.
    // allocating and zeroing memory.
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));

    // defining settings.
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(ipAddress); // To listen for incoming connections.

    // Bind the socket to the address.
    if (bind(socketServer, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr_in)) < 0) {
        perror("Could not bind");
        exit(1);
    }

    // Listen for incoming connections.
    if (listen(socketServer, MAX_QUE) < 0) {
        perror("could not listen");
        exit(1);
    }

    printf("waiting for connection...\n");

    // Accept connection.
    socketClient = accept(socketServer, (struct sockaddr*)&clientAddr, &clientLength);
    if(socketClient < 0) {
        perror("could not accept");
        exit(1);
    }






    //close the socket
    close(socketClient);
    close(socketServer);

}


