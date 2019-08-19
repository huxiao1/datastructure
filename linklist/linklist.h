#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef int datatype;
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	datatype data;
	struct node *next;
}listnode,*linklist;

extern linklist list_create();
extern linklist list_get(linklist H,int pos);
extern linklist list_locate(linklist H,datatype value);
extern int list_insert(linklist H,int pos,datatype value);
extern int list_head_insert(linklist H,datatype value);
extern int list_tail_insert(linklist H);
extern int list_delete(linklist H,int pos);
extern int list_order_insert(linklist H,datatype value);
extern void list_reverse(linklist H);
extern void list_show(linklist H);
extern void list_sort(linklist H);
extern void deleteall(linklist H);

extern linklist yuesefu_create();
extern void yuesefu_show(linklist H);
extern void yuesefu(linklist H,int k,int m);

#endif