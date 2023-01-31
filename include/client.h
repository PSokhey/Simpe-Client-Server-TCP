//
// Created by prabh on 1/30/23.
//
#ifndef DC_SHELL_CLIENT_H
#define DC_SHELL_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096
#define PORT 5000

void runClient(char* ipAddress, char* fileName);

#endif //DC_SHELL_CLIENT_H
