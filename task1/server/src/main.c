#include "../headers/server.h"

int main(void) {
  char* message = "Hello";
  struct server* server = create_server();
  
  /* Log creation */
  printf("SERVER: Server created\n");
  
  /* Send broadcast message */
  send_broadcast(server, message);
  
  /* Log sending of message */
  printf("SERVER: Send broadcast message: %s\n", message);

  /* Free allocated memory */
  free_server(server);
  
  exit(EXIT_SUCCESS);
}
