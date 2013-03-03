#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i=0;

	int seconds=time((time_t*)NULL);
	srand((int)time(0));
	
	
	printf("%d\n",seconds);

	
	for(i=0;i<10;i++)
	{
		printf("%d\n",rand()%100);
	}
}
