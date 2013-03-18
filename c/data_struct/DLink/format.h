#include<stdio.h>
#include<stdlib.h>

typedef struct _D_LINK_LIST
{
	struct _D_LINK_LIST *prev;
	struct _D_LINK_LIST *next;
	int   data;
}D_LINK_LIST;

int print(D_LINK_LIST* thiz);

int dlist_init(D_LINK_LIST *thiz);
int dlist_drop(D_LINK_LIST *thiz);

int dlist_len(D_LINK_LIST *thiz);
int dlist_add(D_LINK_LIST *thiz);
int dlist_del(D_LINK_LIST *thiz);

int dlist_print(D_LINK_LIST* thiz); //打印列表内容
int dlist_find_max(D_LINK_LIST *thiz);
int dlist_sum(D_LINK_LIST *thiz);



