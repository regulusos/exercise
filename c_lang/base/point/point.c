#include <stdio.h>

int main()
{
	int p=3;
	int *p1;
	int **p2;
	p1=&p;
	p2=&p1;

	printf("name\taddr\t\tvalue\t\n");
	printf("p \t%p\t%d\t\n",&p,p);
	printf("p1\t%p\t%p\t\n",&p1,p1);
	printf("p2\t%p\t%p\t\n",&p2,p2);
}
