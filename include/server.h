//
// Created by prabh on 1/30/23.
//

#ifndef DC_SHELL_SERVER_H
#define DC_SHELL_SERVER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 5000
#define MAX_SIZE 4096
#define MAX_QUE 1

void runServer(char* ipAddress);


#endif //DC_SHELL_SERVER_H
