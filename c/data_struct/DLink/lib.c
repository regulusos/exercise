#include"format.h"

int print(D_LINK_LIST *thiz)
{
	printf("%d\n",thiz->data);
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

int dlist_len(D_LINK_LIST *thiz)
{
	D_LINK_LIST *tmp;

	if(thiz->next == NULL)
	{
		return 0;
	}
	else
	{
		int i = 0;
		tmp=thiz->next;
		while(tmp != NULL)
		{
			tmp=tmp->next;
			i++;
		}
		return i; 
	}
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

	if(len > 0 && pos < len && pos > len )
	{
		if(pos == 1)
		{
			drop = thiz->next;
			next = drop->next;

			thiz->next = next;
			next->prev = thiz;

			drop->next = NULL;
			drop->prev = NULL;
			free(drop);
			
		}
		if(pos == len)
		{
			next = thiz->next;
			int i=1;
			while(i < len && thiz != NULL )
			{
				next = next->next;
				i++;
			}
				next->next = NULL;
				
				drop = next->next;
				drop->next = NULL;
				drop->prev = NULL;
				free(drop);

		}
		else
		{
			head = thiz->next;
			int i=1;
			while(i < len && thiz != NULL )
			{
				head = head->next;
				i++;
			}
				drop  = next->next;
				next  = drop->next;

				head->next = next;
				next->prev = head;

				drop->prev = NULL;
				drop->next = NULL;
				free(drop);	
		}
	}

}

int dlist_print(D_LINK_LIST *thiz)
{
	D_LINK_LIST *iter = thiz->next;
	if(iter != NULL)
	{
		print(iter);
		dlist_print(iter);
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
