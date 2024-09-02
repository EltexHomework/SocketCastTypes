#include "../headers/client.h"

/*
 * create_client - used to create an object of client struct.
 * Allocated dynamic memory for client, must be freed by free_client
 * call.
 *
 * Return: pointer to an object of client struct
 */
struct client* create_client() {
  struct client* client = (struct client*) malloc(sizeof(struct client));
  
  if (!client)
    print_error("malloc");
  
  /* Set flag for setsockopt */
  client->flag = 1;

  /* Initialize multicast addr */
  client->addr.sin_family = AF_INET;
  client->addr.sin_port = htons((uint16_t) MULTICAST_PORT); 
  client->addr.sin_addr.s_addr = INADDR_ANY;
  
  /* Create socket */
  client->sfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (client->sfd == -1)
    print_error("socket");
  
  /* Bind client */
  if (bind(client->sfd, (struct sockaddr*) &client->addr, 
           sizeof(client->addr)) == -1)
    print_error("bind");
  
  /* Initialize multicast group */
  client->mreqn.imr_ifindex = 0;
  client->mreqn.imr_address.s_addr = INADDR_ANY;
  client->mreqn.imr_multiaddr.s_addr = inet_addr(MULTICAST_IP);
  
  /* Add to multicast group */
  setsockopt(client->sfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &client->mreqn, sizeof(client->mreqn));

  return client;
}

/*
 * recv_multicast - used to receive multicast message.
 * @client - pointer to an object of client struct
 *
 * Return: buffer with message (must be freed manually)  
 */
char* recv_multicast(struct client* client) {
  int bytes_read;
  socklen_t socklen = sizeof(client->addr); 
  char* buffer = (char*) malloc(BUFFER_SIZE * sizeof(char));
  
  /* Receive multicast message */
  bytes_read = recvfrom(client->sfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*) &client->addr, &socklen);
  if (bytes_read == -1)
    print_error("recvfrom");
  
  return buffer;  
}

/*
 * free_client - used to free memory allocated for
 * object of client struct.
 * @client - pointer to an object of client struct 
 */
void free_client(struct client* client) {
  free(client);
}
