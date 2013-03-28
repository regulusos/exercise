#include "yunsh.h"
/* 实现cd的功能 */
void do_cd(char *argv[])
{
	if(argv[1] != NULL)
	{
		if(chdir(argv[1]) < 0)
			switch(errno)
			{
			case ENOENT:
				printf("DIRECTORY NOT FOUND\n");
				break;
			case ENOTDIR:
				printf("NOT A DIRECTORY NAME\n");
				break;
			case EACCES:
				printf("YOU DO NOT HAVE RIGHT TO ACCESS\n");
				break;
			default:
				printf("SOME ERROR HAPPENED IN CHDIR\n");
			}
	}

}

/* 执行外部命令或应用程序 */
void execute_new(char *argv[])
{
	pid_t pid;

	pid = fork();
	if(pid < 0)
	{
		printf("SOME ERROR HAPPENED IN FORK\n");
		exit(2);
	}
	else if(pid == 0)
	{
		if(execvp(argv[0],argv)<0)
		switch(errno)
		{
			case ENOENT:
				printf("COMMAND OR FILENAME NOT FOUND\n");
				break;
			case EACCES:
				printf("YOU DO NOT HAVE RIGHT TO ACCESS\n");
				break;
			default:
				printf("SOME ERROR HAPPENED IN EXEC\n");
		}
			exit(3);
	}
	else 
		wait(NULL);
}
