#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
	char data;
	struct link *next;
}Lnote;


int linklist_len(Lnote *list)
{
	int i=0;
	Lnote *tmp;
	tmp=list;
	
	while(tmp != NULL)
	{	
		tmp=tmp->next;
		i++;
	}
	return i;
	
}

int linklist_add(Lnote *list,int i,char input)
{
	int length=linklist_len(list);
	int j=0;
	Lnote *new;
	new=(Lnote *)malloc(sizeof(Lnote));
	new->data=input;

	Lnote *tmp;
	Lnote *dest;
	dest=list;
	if(i<=length && i>=0)
	{
		for(j=0;j<i;j++)
		{
			tmp=dest;
			dest=tmp->next;
		}
		tmp->next=new;
		new->next=dest;
		
	}
	else
	{
		printf("out of MAX length");
	}
}

int linklist_print(Lnote *list)
{
	if(list != NULL)
	{
	printf("%d\n",list->data);
	linklist_print(list->next);
	}
}
int linklist_del()
{}

int main()
{

Lnote *new1;
Lnote *new2;
Lnote *new3;

new1=(Lnote *)malloc(sizeof(Lnote));
new2=(Lnote *)malloc(sizeof(Lnote));
new3=(Lnote *)malloc(sizeof(Lnote));


new1->data='\1';
new2->data='\2';
new3->data='\3';

new1->next=new2;
new2->next=new3;

int i;
char input='5';

linklist_print(new1);
linklist_add(new1,1,input);
linklist_add(new1,1,input);
linklist_print(new1);

i=linklist_len(new1);
printf("len is %d\n",i);

}
