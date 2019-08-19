#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include<stdio.h>
#include<stdlib.h>
#include "btree.h"

typedef btree_pnode datatype_stack;

typedef struct node{
	datatype_stack data;
	struct node * next;
}*linklist,listnode;

extern linklist linkstack_create();
extern int linkstack_empty(linklist s);
extern void linkstack_clear(linklist s);
extern int linkstack_push(linklist s,datatype_stack value);
extern void linkstack_pop(linklist s,datatype_stack *t);
extern datatype_stack linkstack_top(linklist s);
extern void linkstack_free(linklist s);

#endif