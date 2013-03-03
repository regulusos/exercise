#include<stdio.h>
#include<stdlib.h>

typedef struct lnote
{
	char data;
	struct lnote* next;
}linklist;

int list_clear(linklist *head)
{
	linklist *tmp;
	tmp=head;
	while(tmp->next != NULL)
	{
		tmp=tmp->next;
		free(tmp);
	}
}

int list_len(linklist *head)
{
	int i=0;
	linklist *tmp;
	tmp=head;
	while(tmp != NULL)
	{
		i++;
		tmp=tmp->next;

	}
	return i;

}

int list_add(linklist* head,int i,char s)
{
		int j;
		linklist *new;
		linklist *tmp;
		linklist *up;
		
		if(i == 0 && head->next == NULL )
		{
			head->data=s;
		}
		else
			if(i > 0 && i <= list_len(head))
			{

				tmp=head;
				for(j=0;j<i-1;j++)
				{
					tmp=tmp->next;	
				}
				up=tmp;
				tmp=tmp->next;	

		
				new=(linklist *)malloc(sizeof(linklist));
				new->data=s;
		
				up->next=new;
				new->next=tmp;
				return 0;
			}	
			else
			{
				printf("error:value is out of list lenght!");
				return 2;
			}
		{
			printf("error:list is no empty!");
			return 1;
		}

		
}

list_print(linklist *head)
{
	if(head != NULL)
	{
		printf("print is %c\n",head->data);
		list_print(head->next);
	}
}

int main()
{
	char a='1';
	char b='2';
	char c='3';
	linklist * list;
	list=(linklist *)malloc(sizeof(linklist));

	
	list_add(list,0,a);
	list_add(list,1,a);
	list_add(list,2,a);
	list_add(list,3,a);

	list_print(list);
	list_add(list,2,b);
	
	list_print(list);
	list_add(list,3,c);

	printf("list len is %d\n",list_len(list));
	list_print(list);
	list_clear(list);
	list_print(list);

}
