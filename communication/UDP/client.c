#include "client_server.h"


#define MSG "Hello OZZZZZZ"

int main()
{
    struct sockaddr_in servaddr; 
	int sock; 
    char buffer[LEN]; 
    int readbyte, len, sendbyte; 
	
	len = sizeof(servaddr);
	
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0)
	{
		perror("socket fail");
		return 0;
	}
	
    memset(&servaddr, 0, sizeof(servaddr)); 
   
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(SERVER_PORT); 
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP); 
      
    sendbyte = sendto(sock, MSG, strlen(MSG), 0, (const struct sockaddr*) &servaddr,  sizeof(servaddr));
    if(sendbyte < 0)
    {
    	perror("message send fail");
    	return 0;
    } 
    printf("Client send message.\n"); 
          
    readbyte = recvfrom(sock, buffer, LEN,  0, (struct sockaddr*) &servaddr, (socklen_t*)&len); 
    if(readbyte < 0)
    {
    	perror("recieve fail");
    	return 0;
    }
    buffer[readbyte] = '\0'; 
    printf("Client recieve meassge : %s\n", buffer); 
  
    close(sock); 
	return 0;
}

