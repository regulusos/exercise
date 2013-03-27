#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int result[4];
int a[30000];

int search()
{
	int max_1=0;
	int max_2=0;
	int max_3=0;
	int max_4=0;
	int max=0;

	if(fork() == 0)
	{
		if(fork() == 0)
		{
				int i;
			for(i=0;i<3;i++)
			{
				if(max_1 < a[i])
					max_1 = a[i];
			}
			result[1] = max_1;
			printf("%d\n",max_1);
			exit(0);
		}
		else	
		{
				int i;
			for(i=3;i<6;i++)
			{
				if(max_2 < a[i])
					max_2 = a[i];
			}
			result[2] = max_2;
			printf("%d\n",max_2);
			exit(0);
		}
	}
	else
	{
		if(fork() == 0)
		{
				int i;
			for(i=6;i<9;i++)
			{
				if(max_3 < a[i])
					max_3 = a[i];
			}
			result[3] = max_3;
			printf("%d\n",max_3);
			exit(0);

		}
		else
		{
				int i;
			for(i=9;i<12;i++)
			{
				if(max_4 < a[i])
					max_4 = a[i];
			}
			result[4] = max_4;
			printf("%d\n",max_4);
		}
		
	}

}

int main()
{

	int i=0;
	int max=0;

	for(i=0;i<4000;i++)
	{
		a[i]=i;
	}
	search();



}



