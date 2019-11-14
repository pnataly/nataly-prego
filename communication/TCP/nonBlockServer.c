#include "client_server.h"
#include "genericVector.h"

#define MSG "Hello from server"
#define BACK_LOG 5

static void Bind(int _sockfd, struct sockaddr_in _serv)
{
	int flags;
	int optval = 1;
	
	if(setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		perror("reuse fail");
		abort();
	}
	if(FAIL==(flags=fcntl(_sockfd, F_GETFL)))
	{
		perror("error at fcntl. F_GETFL.");
		abort();
	}
	if(FAIL==fcntl(_sockfd, F_SETFL, flags|O_NONBLOCK))
	{
		perror("error at fcntl. F_SETFL.");
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
	int flags;
	len = sizeof(_client);
	
  	client_sock = accept(_sockfd, (struct sockaddr*)&_client, &len);
    if(client_sock < 0)
    {
    	if(errno != EAGAIN && errno != EWOULDBLOCK)
    	{
			perror("accept fail");
			abort();
    	}
    	else
    	{
    		return 0;
    	}
    }
	if(FAIL==(flags=fcntl(client_sock, F_GETFL)))
	{
		perror("error at fcntl. F_GETFL.");
		abort();
	}
	if(FAIL==fcntl(client_sock, F_SETFL, flags|O_NONBLOCK))
	{
		perror("error at fcntl. F_SETFL.");
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
	    if(errno != EAGAIN && errno != EWOULDBLOCK)
	    {
			perror("meassge send fail");
			abort();
	    }
	    else
	    {
	    	return;
	    }
	}
	else
	{
		printf("Server sent meassge num%d\n", num);
		++num;
	}
}

static void Swap(Vector* _vec, size_t _index)
{
	void* item1;
	void* item2;
	size_t end_index = Vector_Size(_vec)-1;
	Vector_Get(_vec, _index, &item1);
	Vector_Get(_vec, end_index, &item2);
	Vector_Set(_vec, _index, item2);
	Vector_Set(_vec, end_index, item1);
}

static int Recieve(int _sockfd, Vector* _vec, size_t _index)
{
	static int num = 1;
	char buffer[LEN];
	int read_bytes;
	void* item;
	
	if(_sockfd < 0)
	{
		return -1;
	}
	read_bytes = recv(_sockfd, buffer, LEN, 0);
	if(read_bytes == 0)
	{
		close(_sockfd);
		Swap(_vec, _index);
		Vector_Remove(_vec, &item);
		return -1;
	}	
	if(read_bytes < 0)
	{
	    if(errno != EAGAIN && errno != EWOULDBLOCK)
	    {
			close(_sockfd);
			perror("recieve fail");
			abort();
	    }
	    else
	    {
	    	return -1;
	    }
	}
	else
	{
		buffer[read_bytes] = '\0'; 
		printf("Server recieve message num %d: %s\n",num, buffer);
		++num;
	}
	return 1;
}

static void Transfer(int _sockfd, Vector* _vec, size_t _index)
{
	int res;
	res = Recieve(_sockfd, _vec, _index);
	if(res > 0)
	{
		Send(_sockfd);
	}
	return;
}



int main()
{
	Vector* vec;
	void* item;
	struct sockaddr_in servaddr;
	struct sockaddr_in cliaddr;
	int listen_sock, sock;
	size_t i;
	int* client_sock;
	
	memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP); 
    servaddr.sin_port = htons(SERVER_PORT); 
    
	listen_sock = Init(servaddr);
	
	vec = VectorCreate(SIZE, 0);
	if(vec == NULL)
	{
		abort();
	}
	
	while(1)
	{
		sock = Accept(listen_sock, cliaddr);
		if(sock > 0)
		{
			client_sock = (int*)malloc(sizeof(int));
			if(client_sock == NULL)
			{
				perror("malloc fail");
				abort();
			}
			*client_sock = sock;
			Vector_Append(vec, client_sock);		
		}
		for(i=0; i<Vector_Size(vec); ++i)
		{
			if(Vector_Get(vec, i, &item) != VECTOR_SUCCESS)
			{
				printf("vector get fail\n");
			}
			
			Transfer(*(int*)item, vec, i);		
		}
	}
    
    close(listen_sock);
	return 0;
}

