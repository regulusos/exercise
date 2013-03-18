#include"format.h"

int print(D_LINK_LIST *thiz)
{
	printf("%d\n",thiz->data);
}

int dlist_insert(D_LINK_LIST *thiz, int pos,int data)
{
	int i;
	D_LINK_LIST *tmp=thiz;
	D_LINK_LIST *rear;
	D_LINK_LIST *iter=(D_LINK_LIST *)malloc(sizeof(D_LINK_LIST));
	iter->data=data;
	iter->prev=NULL;
	iter->next=NULL;

	if(pos == 0)
	{
		tmp->next=iter;
		iter->prev=tmp;	
	}
	else
	{
		for(i=0; i < pos; i++)
		{
			tmp = tmp->next;
		}

	
	iter->prev = tmp;
	iter->next = rear;

	tmp->next  = iter;
	rear->prev = iter;
	}
}

int dlist_print(D_LINK_LIST *thiz)
{
	D_LINK_LIST *iter = thiz;
	if(iter != NULL)
	{
		print(iter);
		dlist_print(iter->next);
	}
}






int dlist_find_max(D_LINK_LIST *thiz)
{
	int max = 0;
	D_LINK_LIST *iter = thiz;
	while(iter != NULL && iter != NULL)
	{
		if(max <= iter->data)
		{
			max  = iter->data;
			iter = iter->next;
		}
	}
	return max;
}

int dlist_sum(D_LINK_LIST *thiz)
{
}
