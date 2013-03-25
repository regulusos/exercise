#include"format.h"

int test(D_LINK_LIST *thiz)
{
	printf("%p\n",thiz);
}
int main()
{
	int i;
	D_LINK_LIST *new;
	D_LINK_LIST *tmp;

	new=dlist_init();

	for(i=1;i<=5;i++)
	{
		dlist_insert(new,i,i);
	}

				printf("new is %p\n",new);
				printf("new->next is %p\n",new->next);
				printf("new->next->next is %p\n",new->next->next);

	dlist_print(new);
	dlist_delete(new,5);
	dlist_delete(new,1);
				printf("new is %p\n",new);
				printf("new->next is %p\n",new->next);
				printf("new->next->next is %p\n",new->next->next);
	printf("######################################\n");
	dlist_print(new);
	
	dlist_drop(new);

}

