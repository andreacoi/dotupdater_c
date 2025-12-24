#include <sys/types.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

// function that check if the device is connected
// return 0 if the device is connected, 1 otherwise.
int is_connected() {
  // declare the struct required by the manpage.
  struct addrinfo hints, *res;
  // init the status
  int status;

  // initialize to zero the hints struct  
  memset(&hints, 0, sizeof(hints));
  
  // specify if the check has to be done in IPv4 or IPv6 
  // - if unspec, not important.
  hints.ai_family = AF_UNSPEC;
  //  specify the sock type
  hints.ai_socktype = SOCK_STREAM;  

  // call to getaddrinfo to check the connection
  status = getaddrinfo("www.google.com", "80", &hints, &res);
  // freeing the linked list
  freeaddrinfo(res); 
  return status;
}
