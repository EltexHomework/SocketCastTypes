#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <netinet/in.h>
#include <string.h>

#define BUFFER_SIZE 128
#define BROADCAST_IP "255.255.255.255" 
#define BROADCAST_PORT 77777 
#define print_error(msg) do {perror(msg); \
  exit(EXIT_FAILURE);} while(0)

#endif // !COMMON_H
