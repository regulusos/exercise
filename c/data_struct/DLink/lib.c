#include"format.h"

int print(D_LINK_LIST *thiz)
{
	printf("%d\n",thiz->data);
}

int dlist_init(D_LINK_LIST *thiz)
{
	thiz = (D_LINK_LIST *)malloc(sizeof(D_LINK_LIST));
	if(thiz == NULL)
	{
		return 1;
		thiz->prev = thiz->next = NULL;
	}
	else
	{	return 0;
	}
}

int dlist_len(D_LINK_LIST *thiz)
{
	int i = 0;
	D_LINK_LIST *tmp;
	tmp=thiz;
	while(tmp != NULL)
	{
		tmp=tmp->next;
		i++;
	}
	return i; 
}
int dlist_drop(D_LINK_LIST *thiz)
{
	D_LINK_LIST *tmp=thiz;
	while(tmp != NULL)
	{
		tmp = tmp->next;
		free(tmp);
	}
}

int dlist_insert(D_LINK_LIST *thiz, int pos,int data)
{
	int i;
	int len=dlist_len(thiz);
	D_LINK_LIST *tmp;
	D_LINK_LIST *new;
	
	D_LINK_LIST *iter=(D_LINK_LIST *)malloc(sizeof(D_LINK_LIST));
	iter->data=data;
	iter->prev=NULL;
	iter->next=NULL;

	if(pos < 0 && pos >len)
	{
		printf("error input pos");
		return 1;
	}
	
	if(len == 0 && pos == 0)
	{
		thiz = iter;
		return 0;		
	}
	
	if(len > 0 && pos == 0)
	{
		tmp = thiz;
		iter->next = tmp;
		tmp->prev  = iter;
		return 0;
	}
	if(len > 0 && pos > 0 && pos < len)
	{
		
		i=0;
		tmp=thiz;
		while(i < len-1 && tmp != NULL)
		{
			tmp = tmp->next;
			i++;
		}
			new = tmp->next;

		tmp->next  = iter;
	
		iter->prev = tmp;
		iter->next = new;
		
		new->prev  = iter;
		
	}
	if(len > 0 && len == pos)
	{
		i=0;
		tmp=thiz;
		while(i < len-1 && tmp != NULL)
		{
			tmp = tmp->next;
			i++;
		}
		
		
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
