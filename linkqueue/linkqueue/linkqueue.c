#include "linkqueue.h"

void init_linkqueue(link_pqueue *q)
{
	*q=(link_pqueue)malloc(sizeof(link_queue));
	if(*q==NULL)
	{
		perror("malloc failed\n");
		exit(-1);
	}

	(*q)->front=(linklist *)malloc(sizeof(linklist));
	if(((*q)->front)==NULL)
	{
		perror("malloc failed\n");
		exit(-1);
	}
	(*q)->front->next=NULL;
	(*q)->rear=(*q)->front;
}


int is_empty_linkqueue(link_pqueue q)
{
	if(q->rear==q->front)
		return 1;
	else
		return 0;
}

int in_linkqueue(datatype data,link_pqueue q)
{
	linklist *p;
	p=(linklist *)malloc(sizeof(linklist));
	if(p==NULL)
	{
		perror("malloc failed\n");
		exit(-1);
	}
	p->data=data;
	p->next=q->rear->next;
	q->rear->next=p;
	//q->rear=p;  
	q->rear=q->rear->next;
	return 1;
}

int out_linkqueue(link_pqueue q,datatype *p)
{
	linklist *t;
	if(is_empty_linkqueue(q))
	{
		printf("queue is empty!\n");
		return 0;
	}
	t=q->front;
	q->front=q->front->next;
	*p=q->front->data;
	free(t);
	return 1;
}

void show_linkqueue(link_pqueue q)
{
	linklist *p;
	for(p=q->front->next;p!=NULL;p=p->next)
	{
		printf("%d ",p->data);
	}
	puts("");
}