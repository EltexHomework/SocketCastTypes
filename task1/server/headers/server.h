#ifndef SERVER_H
#define SERVER_H

#include "../../common/headers/common.h"

/**
 * Used as broadcast server. Creates socket and
 * sets it to broadcast mode. Sends "Hello" message
 * to all peers in LAN.
 */
struct server {
  struct sockaddr_in broadcast_addr;
  int sfd;
  int flag;
};

struct server* create_server();

void send_broadcast(struct server* server, char* message);

void free_server(struct server* server);

#endif // !SERVER_H
