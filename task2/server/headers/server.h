#ifndef SERVER_H
#define SERVER_H

#include "../../common/headers/common.h"

/**
 * Used as multicast server. 
 * Creates socket and sends 
 * "Hello" message
 * to all peers in group.
 */
struct server {
  struct sockaddr_in multicast_addr;
  int sfd;
};

struct server* create_server();

void send_multicast(struct server* server, char* message);

void free_server(struct server* server);

#endif // !SERVER_H
