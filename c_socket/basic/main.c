#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <string.h>
#include <unistd.h> // close() socket


// Following https://www.binarytides.com/socket-programming-c-linux-tutorial/

int main(int argc, char *argv[])
{
	// Initialize Variables
	int socket_desc;
	struct sockaddr_in server;
	char *message;
	char server_reply[2000];
	
	// Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);       //AF_INET = IPV4,  SOCK_STREAM = TCP, protocol 0 (or IPPROTO_IP) is IP
	if (socket_desc == -1)
		printf("Could not create a socket.\n");
	
	server.sin_addr.s_addr = inet_addr("172.217.5.100"); // Google.com
	server.sin_family = AF_INET;                         // (IPv4)
	server.sin_port = htons(80);                         // Port 80
	
	// Connect to remote server
	if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		printf("Connection Error. \n");
		return 1;
	}
	
	printf("Connected!\n");	
	
	// Send data to website to get HTTP webpage
	message = "GET / HTTP/1.1\r\n\r\n";
	if(send(socket_desc, message, strlen(message), 0) < 0)
	{
		printf("Send failed.\n");
		return 1;
	}
	
	// Receive reply from web server
	if (recv(socket_desc, server_reply, 2000, 0) < 0)
	{
		printf("recv failed.\n");
	}
	
	printf("Reply received!\n");
	puts(server_reply);
	
	close(socket_desc);
	
	return 0;
}
