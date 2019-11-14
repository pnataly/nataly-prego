#include "client_server.h"

#define MSG "Hello from server"
#define BACK_LOG 5

static void Bind(int _sockfd, struct sockaddr_in _serv)
{
	int optval = 1;
	
	if(setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		perror("reuse fail");
		abort();
	}

	if(bind(_sockfd, (const struct sockaddr*)&_serv, sizeof(_serv)) < 0) 
    { 
        perror("bind failed"); 
		abort();
    }
}

static void Listen(int _sockfd)
{
    if(listen(_sockfd, BACK_LOG) < 0)
    {
    	perror("listen fail");
		abort();
    }
}

static int Init(struct sockaddr_in _serv)
{
	int listen_sock;
	
	listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if(listen_sock < 0)
	{
		perror("socket fail");
		abort();
	}
	
	Bind(listen_sock, _serv);
 
    Listen(listen_sock);

	return listen_sock;
}

static int Accept(int _sockfd ,struct sockaddr_in _client)
{
	int client_sock;
	socklen_t len;
	
	len = sizeof(_client);
	
  	client_sock = accept(_sockfd, (struct sockaddr*)&_client, &len);
    if(client_sock < 0)
    {
		perror("accept fail");
		abort();
    }

	return client_sock;
}


static void Send(int _sockfd)
{
	static int num = 1;
	int sent_bytes;
	if(_sockfd < 0)
	{
		return;
	}
	sent_bytes = send(_sockfd, MSG, strlen(MSG), 0);
	if(sent_bytes <= 0)
	{
		perror("meassge send fail");
		abort();
	}
	printf("Server sent meassge num%d\n", num);
	++num;
}


static int Recieve(int _sockfd)
{
	static int num = 1;
	char buffer[LEN];
	int read_bytes;
	if(_sockfd < 0)
	{
		return -1;
	}
	read_bytes = recv(_sockfd, buffer, LEN, 0);
	if(read_bytes == 0)
	{
		close(_sockfd);
		return -1;
	}	
	if(read_bytes < 0)
	{
		close(_sockfd);
		perror("recieve fail");
		abort();
	}

	buffer[read_bytes] = '\0'; 
	printf("Server recieve message num %d: %s\n",num, buffer);
	++num;
	return 1;
}

static void Transfer(int _sockfd)
{
	int res;
	res = Recieve(_sockfd);
	if(res > 0)
	{
		Send(_sockfd);
	}
	return;
}



int main()
{
	struct sockaddr_in servaddr;
	struct sockaddr_in cliaddr;
	int listen_sock, sock, maxfd, activity, i;
	fd_set temp, master; 
	
	memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP); 
    servaddr.sin_port = htons(SERVER_PORT); 
    
	listen_sock = Init(servaddr);
	sock = Accept(listen_sock, cliaddr);
	
	maxfd = 1024; 
	FD_ZERO(&master);
	FD_SET(listen_sock, &master); 
    
	while(1)
    { 
		temp = master;
		if(activity = (select(maxfd+1, &temp, NULL, NULL, NULL) < 0))
		{
			perror("select error");
			abort();
		}
		for(i=listen_sock; i<maxfd; ++i)
		{
			if(FD_ISSET(i, &temp))	
			{
				if(i == listen_sock)
				{
					sock = Accept(listen_sock, cliaddr);
					FD_SET(sock, &temp);
				}
				else
				{
					Transfer(i);
				}
			}
		}
    }
    
	return 0;
}


