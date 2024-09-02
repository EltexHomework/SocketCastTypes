#include "../headers/server.h"

int main(void) {
  char* message = "Hello";
  struct server* server = create_server();
  
  /* Log creation */
  printf("SERVER: Server created\n");
  
  /* Send multicast message */
  send_multicast(server, message);
  
  /* Log sending of message */
  printf("SERVER: Send multicast message: %s\n", message);

  /* Free allocated memory */
  free_server(server);
  
  exit(EXIT_SUCCESS);
}
