#include"format.h"

int test(D_LINK_LIST *thiz)
{
	printf("%p\n",thiz);
}
int main()
{
	int i;
	D_LINK_LIST *new;

	new=dlist_init();

	for(i=1;i<=5;i++)
	{
		dlist_insert(new,i,i);
	}


	dlist_print(new);
	dlist_drop(new);
	dlist_print(new);

}

