#ifndef CLIENT_H
#define CLIENT_H

#include "../../common/headers/common.h"

/**
 * Used as client app to receive broadcast message
 * sent by server.
 */
struct client {
  struct sockaddr_in broadcast_addr;
  int sfd;
};

struct client* create_client();

char* recv_broadcast(struct client* client); 

void free_client(struct client* client);

#endif // !CLIENT_H
