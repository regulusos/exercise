#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{

	pid_t pid;
	pid = fork();
	switch(pid)
	{
		case 0 :	
					printf("Child is running CurPid is %d ParentPid is %d %d \n",pid,getpid(),getppid());
					break;
		case -1:	
					printf("Process creation is fialed \n");
					break;
		default :	
					printf("Parent is running CurPid is %d ParentPid is %d %d \n",pid,getpid(),getppid());
					break;

	}
	while(1);

}
