//
// Created by prabh on 1/30/23.
//

#include "client.h"


void runClient(char* ipAddress, char* fileName) {

    int socketClient; //socket file descriptor for connection.
    int fileFD;
    struct sockaddr_in serverAddr; // address to server.
    char buffer[MAX_BUFFER_SIZE];
    int bytesRead = 0;

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

    // open the file
    fileFD = open(fileName, O_RDONLY);
    if(fileFD < 0) {
        perror("Could not open file.");
        exit(1);
    }

    // send file to the server.
    while ((bytesRead = read(fileFD, buffer, MAX_BUFFER_SIZE)) > 0) {
        if (send(socketClient, buffer, bytesRead, 0) < 0) {
            perror("send");
            exit(1);
        }
    }

    // close file descriptor when done.
    close(fileFD);

    // clear buffer for getting a response from server.
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // read response from server and display to user.
    if(recv(socketClient, buffer, MAX_BUFFER_SIZE,0) < 0) {
        perror("Could not read response from user.");
        exit(1);
    }

    // Close socket before exiting program.
    close(socketClient);

}



