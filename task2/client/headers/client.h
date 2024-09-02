#ifndef CLIENT_H
#define CLIENT_H

#include "../../common/headers/common.h"

/**
 * Used as client app to receive multicast message
 * sent by server.
 */
struct client {
  struct ip_mreqn mreqn; 
  struct sockaddr_in addr;
  int flag;
  int sfd;
};

struct client* create_client();

char* recv_multicast(struct client* client); 

void free_client(struct client* client);

#endif // !CLIENT_H
