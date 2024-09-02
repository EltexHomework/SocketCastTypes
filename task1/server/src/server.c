#include "../headers/server.h"

/*
 * create_server - used to create an object of server
 * struct, initializes broadcast address, creates socket and
 * sets it to broadcast mode.
 *
 * Return: pointer to an object of server struct  
 */
struct server* create_server() {
  struct server* server = (struct server*) malloc(sizeof(struct server));
  
  if (!server)
    print_error("malloc");

  /* Initialize flag for setsockopt */
  server->flag = 1;
  
  /* Initialize socket */
  server->sfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (server->sfd == -1)
    print_error("socket");
  setsockopt(server->sfd, SOL_SOCKET, SO_BROADCAST, &server->flag, sizeof(server->flag));

  /* Initialize broadcast address */
  server->broadcast_addr.sin_family = AF_INET;
  server->broadcast_addr.sin_port = htons((uint16_t) BROADCAST_PORT);
  server->broadcast_addr.sin_addr.s_addr = inet_addr(BROADCAST_IP);

  return server;
}

/*
 * send_broadcast - used to send broadcast message with 
 * string containing in message buffer
 * @server - pointer to an object of server struct
 * @message - message buffer
 */
void send_broadcast(struct server* server, char* message) {
  ssize_t bytes_send;
  socklen_t broadcast_len = sizeof(server->broadcast_addr); 
  
  /* Send broadcast message */
  bytes_send = sendto(server->sfd, message, strlen(message), 0, 
         (struct sockaddr*) &server->broadcast_addr, broadcast_len);
  
  /* Error occured */
  if (bytes_send == -1)
    print_error("sendto");
}

/*
 * free_server - used to free allocated memory for
 * object of server struct.
 * @server - pointer to an object of server struct
 */
void free_server(struct server* server) {
  free(server);
}
