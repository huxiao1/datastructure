#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include<stdlib.h>
#include "btree.h"

typedef btree_pnode datatype; 

//链式队列的节点类型
typedef struct qnode{
	datatype data;
	struct qnode *next;
}qlinklist;

typedef struct
{
	qlinklist *front,*rear;
}link_queue,*link_pqueue;

extern void init_linkqueue(link_pqueue *q);
extern int is_empty_linkqueue(link_pqueue q);
extern int in_linkqueue(datatype data,link_pqueue q);
extern int out_linkqueue(link_pqueue q,datatype *p);




#endif