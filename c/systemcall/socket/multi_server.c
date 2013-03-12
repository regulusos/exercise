#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024
#define LISTEN_PORT 6000

int main(int argc,char **argv)
{
	int		i;
	int		sock_recv;
	int		incoming_len;
	int		recv_msg_size;
	int		select_ret;

	char	buf[BUF_SIZE];	

	fd_set	readfds;

	struct	sockaddr_in	my_addr;
	struct	sockaddr_in	remote_addr;
	struct	timeval		timeout={0,0};

	sock_recv=socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sock_recv < 0)
	{
		printf("socket() failed\n");
		exit (0);
	}

	memset(&my_addr,0,sizeof(my_addr));

	my_addr.sin_family      = AF_INET;
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	my_addr.sin_port        = htons((unsigned short)LISTEN_PORT);

	i=bind(sock_recv,(struct sockaddr *)&my_addr,sizeof(my_addr));
	if(i < 0)
	{
		printf("bind() failed\n");
		exit(0);
	}

	while(1)
	{
		do
		{
			FD_ZERO(&readfds);
			FD_SET(sock_recv,&readfds);
			select_ret = select(sock_recv+1,&readfds,NULL,NULL,&timeout);
			
			if(select_ret > 0)
			{
				incoming_len = sizeof(remote_addr);
				recv_msg_size = recvfrom(sock_recv,buf,BUF_SIZE,0,(struct sockaddr *)&remote_addr,&incoming_len);
				if(recv_msg_size > 0)
				{
					buf[recv_msg_size]='\0';
					printf("From %s received:%s\n",inet_ntoa(remote_addr.sin_addr),buf);
				}
			}
		}
		while(select_ret > 0);
			if(strcmp(buf,"shutdown")==0)
				break;
		close(sock_recv);
	}

}
