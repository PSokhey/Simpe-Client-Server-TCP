//
// Created by prabh on 1/30/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "client.h"


void runClient(char* ipAddress, char* fileName) {

    int socketClient; //socket file descriptor for connection.
    struct sockaddr_in serverAddr; // address to server.
    char buffer[MAX_BUFFER_SIZE];
    int bytesRead;

    // creating the socket.
    socketClient = socket(AF_INET, SOCK_STREAM, 0);
    if (socketClient < 0) {
        perror("could not create client socket.");
        exit(1);
    }

    // set up and zero out memory for server address struct.
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));

    // set up server settings.
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(ipAddress);

    // Connect to the server.
    if(connect(socketClient, (struct sockaddr*) &serverAddr, sizeof(struct sockaddr_in)) < 0) {
        perror("Could not connect to the server");
        exit(1);
    }



    // Close socket before exiting program.
    close(socketClient);

}



