#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int create_server()
{
	int ret;
	/* Construct server address and port structure */
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(1202);
	inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
	
	/* Build a socket for IPV4 */
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	/* We can cast struct sockaddr_in to struct sockaddr with ease and safety */
	ret = bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
	
	if(ret == -1)
	{
		fprintf(stderr, "%s\n", strerror(errno));
	}
	
	if(listen(server_socket, 0) == -1)
	{
		fprintf(stderr, "%s\n", strerror(errno));
	}
	
	struct sockaddr_in peer_addr;
	socklen_t peer_addr_length;
	if(accept(server_socket, (struct sockaddr*)&peer_addr, &peer_addr_length) < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
	}
	
	close(server_socket);
	
	return 0;
}
