#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int connect_to_server()
{
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(1202);
	inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
	
	int client_fd = socket(AF_INET,  SOCK_STREAM, 0);
	
	connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	
	return 0;
}
