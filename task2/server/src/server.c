#include "../headers/server.h"

/*
 * create_server - used to create an object of server
 * struct, initializes multicast address, creates socket and
 * sets it to multicast mode.
 *
 * Return: pointer to an object of server struct  
 */
struct server* create_server() {
  struct server* server = (struct server*) malloc(sizeof(struct server));
  
  if (!server)
    print_error("malloc");

  /* Initialize socket */
  server->sfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (server->sfd == -1)
    print_error("socket");

  /* Initialize multicast address */
  server->multicast_addr.sin_family = AF_INET;
  server->multicast_addr.sin_port = htons((uint16_t) MULTICAST_PORT);
  server->multicast_addr.sin_addr.s_addr = inet_addr(MULTICAST_IP);

  return server;
}

/*
 * send_multicast - used to send multicast message with 
 * string containing in message buffer
 * @server - pointer to an object of server struct
 * @message - message buffer
 */
void send_multicast(struct server* server, char* message) {
  ssize_t bytes_send;
  socklen_t multicast_len = sizeof(server->multicast_addr); 
  
  /* Send multicast message */
  bytes_send = sendto(server->sfd, message, strlen(message), 0, 
         (struct sockaddr*) &server->multicast_addr, multicast_len);
  
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
