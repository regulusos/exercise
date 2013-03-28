#include"yunsh.h"

main()
{
	char *cmd = (void *)malloc(256*sizeof(char));
	char *cmd_arg[10];
	int  cmdlen,i,j,tag;

	do{
		/* 初始化cmd */
		for(i = 0; i < 255; i++) 
			cmd[i] = '\0';
		printf("YunSH /> ");
	
		fgets(cmd,256,stdin);

		cmdlen = strlen(cmd);
		cmdlen--;
		cmd[cmdlen] = '\0';

		/* 把命令行分解为指针数组cmd_arg */
		for(i=0;i<10;i++)
		{
			cmd_arg[i]=NULL;
		}
		i = 0;
		j=0; 
		tag = 0;

		while(i < cmdlen && j < 10)
		{
			if(cmd[i] == ' ')
			{
				cmd[i] = '\0';
				tag = 0;
			}
			else
			{
				if(tag == 0)
					cmd_arg[j++]=cmd+i;
				tag = 1;
			}
			i++;
		}
		
		/* 如果参数超过10个，就打印错误，并忽略当前输入 */
		if(j >= 10 && i < cmdlen)
		{
			printf("TOO MANY ARGUMENTS\n");
			continue;
		}

		/* 命令quit：退出 Shell */
		if(strcmp(cmd_arg[0],"quit") == 0)
			break;
		
		if(strcmp(cmd_arg[0],"\r") == 0)
		{
			printf("There is No input,Can I help you?\n");
		}

		/* 命令cd */
		if(strcmp(cmd_arg[0],"cd") == 0){
			do_cd(cmd_arg);
			continue;
		}
		
		/* 外部命令或应用程序 */
		execute_new(cmd_arg);
	}while(1);
}

