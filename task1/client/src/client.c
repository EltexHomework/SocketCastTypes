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
  
  /* Initialize broadcast addr */
  client->broadcast_addr.sin_family = AF_INET;
  client->broadcast_addr.sin_port = htons((uint16_t) BROADCAST_PORT); 
  client->broadcast_addr.sin_addr.s_addr = inet_addr(BROADCAST_IP);
  
  /* Create socket */
  client->sfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (client->sfd == -1)
    print_error("socket");
  
  /* Bind client to broadcast address */
  if (bind(client->sfd, (struct sockaddr*) &client->broadcast_addr, 
           sizeof(client->broadcast_addr)) == -1)
    print_error("bind");

  return client;
}

/*
 * recv_broadcast - used to receive broadcast message.
 * @client - pointer to an object of client struct
 *
 * Return: buffer with message (must be freed manually)  
 */
char* recv_broadcast(struct client* client) {
  int bytes_read;
  socklen_t socklen = sizeof(client->broadcast_addr); 
  char* buffer = (char*) malloc(BUFFER_SIZE * sizeof(char));
  
  /* Receive broadcast message */
  bytes_read = recvfrom(client->sfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*) &client->broadcast_addr, &socklen);
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
