#ifndef _DLIST_H_
#define _DLIST_H_
#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int data;
	struct node *prior;
	struct node *next;
}dlistnode;

extern dlistnode * dlist_create();
extern void dlist_show(dlistnode * H);
extern dlistnode * dlist_get(dlistnode *H,int pos);
extern int dlist_insert(dlistnode * H,int value,int pos);
extern int dlist_delete(dlistnode * H,int pos);

#endif