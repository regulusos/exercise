#include "format.h"
int main()
{

	char a[19]="1234";
	char b[19]="sadfdsfasdfasdf";
	char *s=a;
	char *t=b;

	char c[22]="2222";
	char d[45]="2222";
	printf("cmp c & d result is%d\n",strcmp(c,d));

	printf("%s\n",s);
	printf("%s\n",t);
	printf("len of s is:\n %d\n",strlen(s));
	strcat(s,t);
	printf("cat t >> s is :\n %s\n",s);
	printf("new string t is :\n %s\n",t);
	strcpy(s,t);
	printf("new string s is :\n %s\n",s);
	printf("new string t is :\n %s\n",t);
}

