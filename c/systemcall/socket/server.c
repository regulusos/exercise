#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024
#define LISTEN_PORT 6000

int main(int argc,char *argv[])
{
	int		sock_listen;
	int		sock_recv;
	struct	sockaddr_in my_addr;
	struct	sockaddr_in recv_addr;
	
	int		i,addr_size,bytes_received;
	fd_set	readfds;
	struct	timeval timeout={0,0};
	int		incoming_len;
	struct	sockaddr remote_addr;
	int		recv_msg_size;
	char	buf[BUF_SIZE];
	int		select_ret;

	sock_listen=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sock_listen < 0)
	{
		printf("socket() failed\n");
		exit(0);
	}

	memset(&my_addr,0,sizeof(my_addr));		//清空结构
	my_addr.sin_family=AF_INET;			//地址类别
	my_addr.sin_addr.s_addr=htonl(INADDR_ANY);	//当前的ＩＰ
	my_addr.sin_port= htons((unsigned short)LISTEN_PORT);//将套接字帮顶到本地

	i=bind(sock_listen,(struct sockaddr *)&my_addr,sizeof(my_addr));
	
	if(i<0)
	{
		printf("bind() failed\n");
		exit (0);
	}

	i=listen(sock_listen,5);
	
	if(i<0)
	{
		printf("listen failed\n");
		exit (0);

	}
	addr_size=sizeof(recv_addr);
	sock_recv=accept(sock_listen,(struct sockaddr *) &recv_addr,&addr_size);
	
	while(1)
	{
		bytes_received=recv(sock_recv,buf,BUF_SIZE,0);
		buf[bytes_received]='\0';
		printf("Reveived:%s\n",buf);
		if(strcmp(buf,"shutdown")==0)
			break;
	}
	close(sock_recv);
	close(sock_listen);
	
}
