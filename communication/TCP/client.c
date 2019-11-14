#include "client_server.h"

#define MSG "Good morning JEFFF"


static int Init()
{
	int sock;
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("socket fail");
		abort();
	}
    return sock;
}

static void Connect(int _sockfd, struct sockaddr_in _struct)
{
	if(connect(_sockfd, (struct sockaddr*)&_struct, sizeof(_struct)) < 0)
	{
		perror("connection fail");
		abort();
	}
}

static void Send(int _sockfd)
{
	int sent_bytes;

	sent_bytes = send(_sockfd, MSG, strlen(MSG), 0);
	if(sent_bytes < 0)
	{
		perror("meassge send fail");
		abort();
	}
	printf("Client sent meassge\n");
}

static void Recieve(int _sockfd)
{
	char buffer[LEN];
	int read_bytes;
	
	read_bytes = recv(_sockfd, buffer, LEN, 0);
	if(read_bytes < 0)
	{
		close(_sockfd);
		perror("recieve fail");
		abort();
	}
	buffer[read_bytes] = '\0'; 
	printf("Client recieve message: %s\n", buffer);
}

static void Transfer(int _sockfd)
{
	int i;
	for(i = 0; i < NUM; ++i)
	{
		Send(_sockfd);
	
		Recieve(_sockfd);
		
		sleep(1);
	}
}


int main()
{
	int sock;
    struct sockaddr_in servaddr; 
	
	sock = Init();
	
	memset(&servaddr, 0, sizeof(servaddr)); 
   
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(SERVER_PORT); 
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP); 
    	
	Connect(sock, servaddr);
	
	Transfer(sock);
	
	close(sock);
	
	return 0;
}

