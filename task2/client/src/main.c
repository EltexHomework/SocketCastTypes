#include "../headers/client.h"

int main(void) {
  char* buffer;
  struct client* client = create_client();
  
  /* Log creation */
  printf("CLIENT: Client created. Waiting for multicast message\n");

  /* Receive broadcast message */
  buffer = recv_multicast(client);
  
  /* Log message */
  printf("CLIENT: Received muticast message: %s\n", buffer);
  
  /* Free allocated memory */
  free(buffer);
  free_client(client);
  exit(EXIT_SUCCESS);
}
