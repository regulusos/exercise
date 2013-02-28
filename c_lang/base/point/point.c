#include<stdio.h>

int mian()
{
	int p=3;
	int *p1;
	int **p2;
	p1=&p;
	p2=&p1;

	printf("addr\tvalue\t\n")
	printf("%p\t%d\t\n",&p,p);
	printf("%p\t%d\t\n",&p1,p1);
	printf("%p\t%d\t\n",&p2,p2);
}
