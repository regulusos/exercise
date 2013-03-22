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


	dlist_print(new);
	dlist_delete(new,1);
	printf("######################################\n");
	dlist_print(new);
	
	dlist_drop(new);

}

