#include"format.h"

int test(D_LINK_LIST *thiz)
{
	printf("%p\n",thiz);
}
int main()
{
	D_LINK_LIST *new;

	new=dlist_init();

	//new=(D_LINK_LIST *)malloc(sizeof(D_LINK_LIST));
	//new->data=0;
	//new->next=NULL;
	//new->prev=NULL;

	int i;
	for(i=1;i<30000;i++)
	{
	dlist_insert(new,i,i);
	}

	printf("## %d\n",dlist_len(new));

	int max;
	max=dlist_find_max(new);

	printf("max is %d",max);

	dlist_drop(new);

}

