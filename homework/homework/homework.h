#ifndef _HOMEWORK_H_
#define _HOMEWORK_H_
#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int data;
	struct node *prior;
	struct node *next;
}dlistnode;

extern dlistnode * dlist_create();
extern dlistnode *list_create();

#endif