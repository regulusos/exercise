#include"format.h"

int print(D_LINK_LIST *thiz)
{
	printf("%d\n",thiz->data);
}

int dlist_print(D_LINK_LIST *thiz)
{
	D_LINK_LIST *iter = thiz->next;
	while(iter != NULL)
	{
		print(iter);
		iter = iter->next;
	}
}

int dlist_init()
{
	D_LINK_LIST* thiz = (D_LINK_LIST *)malloc(sizeof(D_LINK_LIST));
	if(thiz == NULL)
	{
		printf("malloc is fialed!");
		return 1;
	}
	else
	{	
		thiz->prev = thiz->next = NULL;
		return thiz;
	}
}

int dlist_free(D_LINK_LIST *thiz)
{
	D_LINK_LIST *tmp;
	tmp=thiz;
	if(tmp != NULL)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		free(tmp);
		return 0;
	}
	else
	{
		printf("error can't free a empty memdiv\n");
		return 1;
	}


}


D_LINK_LIST* dlist_foreach(D_LINK_LIST *thiz,int pos)
{
	int i = 0;
	int len = dlist_len(thiz);
	//D_LINK_LIST *iter=thiz->next;
	D_LINK_LIST *iter=thiz;
	iter=thiz;

	if(pos > len)
		printf("postion is long than real len ... pos is %d\n len is %d\n",pos,len);
	

	while(i < pos )
	{
		iter = iter->next;
		i++;
	}
	return iter;
}

int dlist_len(D_LINK_LIST *thiz)
{
	D_LINK_LIST *tmp=thiz->next;

	int i = 0;
	if(tmp == NULL)
	{	
		return 0;
	}
	else
	{	
		while(tmp != NULL)
		{
			tmp = tmp->next;
			i++;
		}
		return i;
	}
}

int dlist_drop(D_LINK_LIST *thiz)
{
	D_LINK_LIST *tmp ;
	while( thiz != NULL)
	{
		tmp  = thiz;
		thiz = thiz->next;
		
		tmp->next = NULL;
		tmp->prev = NULL;
		free(tmp);
	}

	/*
	if(thiz != NULL)
	{
		dlist_drop(thiz->next);
		thiz->next = NULL;
		thiz->prev = NULL;
		free(thiz);
	}
	*/

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

	if(pos <= 0 )
	{
		if(pos <=0 )
		{	
			printf("pos is must be > 0 ");
		    return 1;
		}
		if(pos > len)
		{	
			printf("pos is must be < len ");
		    return 2;
		}
	}
	
	if(len == 0 && pos == 1)
	{
		tmp = thiz;
		
		tmp->prev  = NULL;
		tmp->next  = iter;

		iter->prev = tmp;
		iter->next = NULL;

	}
	
	if(len > 0 && pos == 1)
	{
		tmp = thiz;
		new = thiz->next;

		tmp->prev  = NULL;
		tmp->next  = iter;

		iter->prev = tmp ;
		iter->next = new ;


	}
	
	if(len > 0 && pos-len == 1)
	{
		int i = 1;
		tmp = thiz->next;

		while(i < len)
		{
			tmp=tmp->next;
			i++;
		}
		tmp->next  = iter;
		iter->prev = tmp;
	}
	
	if(len > 0 && pos > 1 && pos <= len)
	{
		
		int i = 1;

		tmp = thiz->next;
		while(i < pos )
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
}

int dlist_delete(D_LINK_LIST *thiz,int pos)
{
	int len=dlist_len(thiz);
	
	D_LINK_LIST *drop;
	D_LINK_LIST *next;
	D_LINK_LIST *head;

	if(pos == 1 && len == 1)
	{
		drop = thiz->next;
		thiz->next = NULL;
		dlist_drop(drop);
	}
	if(pos == 1 && len > 1)
	{
		drop = dlist_foreach(thiz,pos);
		next = dlist_foreach(thiz,pos+1);
		printf("drop is %p\n",drop);
		printf("next is %p\n",next);
		thiz->next = next;
		next->prev = thiz;
		dlist_free(drop);
		}
	if(pos >1 && len > 1 && pos == len)
	{
			
		drop = dlist_foreach(thiz,pos);
		head = dlist_foreach(thiz,pos-1);
		head->next = NULL;
		dlist_free(drop);
	}
	if(pos >1 && len >1 && pos < len)	
	{

		head = dlist_foreach(thiz,pos-1);
		drop = dlist_foreach(thiz,pos);
		next = dlist_foreach(thiz,pos+1);
		head->next = next;
		next->prev = head;
		dlist_free(drop);
	}
}

int dlist_find_max(D_LINK_LIST *thiz)
{
	int max = 0;
	D_LINK_LIST *iter = thiz->next;
	while(iter != NULL)
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
