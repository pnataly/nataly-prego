#include <netdb.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/select.h>
#include <errno.h>
#include <fcntl.h>


#define SERVER_IP "192.168.0.220"
#define SERVER_PORT 1234
#define LEN 64
#define NUM 4
#define FAIL -1
#define SIZE 100
