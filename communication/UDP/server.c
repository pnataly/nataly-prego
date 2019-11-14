#include "client_server.h"

#define MSG "Hello OZZZZZ"

int main()
{
	struct sockaddr_in servaddr;
	struct sockaddr_in cliaddr;
	int sock;
    int len, readbyte, sendbyte; 
    char buffer[LEN]; 
    
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0)
	{
		perror("socket fail");
		return 0;
	}
	
	len = sizeof(cliaddr);
	memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP); 
    servaddr.sin_port = htons(SERVER_PORT); 
    
    if(bind(sock, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) 
    { 
        perror("bind failed"); 
		return 0;
    } 
    
    readbyte = recvfrom(sock, buffer, LEN, 0, (struct sockaddr*) &cliaddr, (socklen_t*)&len); 
    if(readbyte < 0)
    {
    	perror("recieve fail");
    	return 0;
    }
    buffer[readbyte] = '\0'; 
    printf("Server recieve meassge : %s\n", buffer); 
    
    sendbyte = sendto(sock, MSG, strlen(MSG), 0, (const struct sockaddr*) &cliaddr, len);
    if(sendbyte < 0)
    {
    	perror("meassge send fail");
    	return 0;
    } 
    printf("Server send message.\n");
    
    close(sock);
	return 0;
}

