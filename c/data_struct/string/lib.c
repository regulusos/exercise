#include "format.h"

int strlen(char* s)
{
	char* sc=s;
	while(*(++sc) != '\0')
	{
		/*do nothing*/;
	}
	return sc-s;
}

int strcpy(char* s,char* t)
{
	//if(strlen(t)<=strlen(s))
	//{
		while(*t != '\0')
		{
			*(s++)=*(t++);
		}
		*s='\0';
		return 0;
	//}
	//else
	//	return 1;
}
int strcmp(char* s,char* t)
{
	if(strlen(s) > strlen(t))
		return 1;
	if(strlen(s) < strlen(t))
		return -1;
	if(strlen(s)==strlen(t))
	{

		while(1)
		{
			if(*s > *t)
			{
				return 1;
				break;
			}
			if(*s < *t)
			{
				return -1;
				break;
			}
			if(*s=='\0' && *t =='\0' )
			{
				return 0;
				break;
			}
			else
			{
				t++;
				s++;
			}

		}

	}
}

int strcat(char *s,char* t)
{
	int i=strlen(s);

	while(*t != '\0')
	{
		 
		s[i++]=*(t++);
	}
	s[i]='\0';
	return 0;
}

