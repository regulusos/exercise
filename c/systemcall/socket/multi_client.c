#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>

#define BUF_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int main(int argc,char *argv[])
{
	int	sock_send;
	int	send_len;
	int	bytes_send;
	char	text[80];
	char	buf[BUF_SIZE];
	struct  sockaddr_in 	addr_send;
	
	sock_send=socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sock_send < 0)
	{
		printf("socket() failed!\n");
		exit (0);
	}
	
	memset(&addr_send,0,sizeof(addr_send));
	addr_send.sin_family =AF_INET;
	addr_send.sin_addr.s_addr = inet_addr(SERVER_IP);
	addr_send.sin_port = htons((unsigned short)SERVER_PORT);
	
	while(1)
	{
	printf("Send?\n");
	scanf("%s",text);
	if(strcmp(text,"quit")==0)
		break;
	
	strcpy(buf,text);
	send_len=strlen(text);
	bytes_send=sendto(sock_send,buf,send_len,0,(struct sockaddr_in *)&addr_send,sizeof(addr_send));
	}
	close(sock_send);
}
