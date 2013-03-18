#include"format.h"

int test(D_LINK_LIST *thiz)
{
	printf("%p\n",thiz);
}
int main()
{
	D_LINK_LIST *new;
	new=(D_LINK_LIST *)malloc(sizeof(D_LINK_LIST));
	new->data=0;

	dlist_insert(new,0,0);
	dlist_insert(new,0,1);
	dlist_insert(new,0,2);
	dlist_insert(new,0,2);
	dlist_insert(new,0,2);
	dlist_insert(new,0,2);
	//dlist_insert(new,1,1);
	//dlist_insert(new,1,1);
	//dlist_insert(new,1,1);

	//printf("%d\n",dlist_len(new));

	//dlist_insert(new,1,1);
	//dlist_print(new);
	//dlist_drop(new);
	dlist_print(new);

}

