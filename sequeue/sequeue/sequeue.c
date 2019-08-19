#include "sequeue.h"
/*
seq_pqueue init_seqqueue()
{
	seq_pqueue q;

	q=(seq_pqueue)malloc(sizeof(seq_queue));
	if(q==NULL)
	{
		perror("malloc");
		exit(-1);
	}
	q->front = q->rear = MAXSIZE-1;
	return q;
}
*/
void init_seqqueue(seq_pqueue *q)
{
	*q=(seq_pqueue)malloc(sizeof(seq_queue));
	if((*q)==NULL)
	{
		perror("malloc");
		exit(-1);
	}
	(*q)->front = (*q)->rear = MAXSIZE-1;
}

int is_full_seqqueue(seq_pqueue q)
{
	if((q->rear+1)%MAXSIZE==q->front)
		return 1;
	else
		return 0;
}

int is_empty_seqqueue(seq_pqueue q)
{
	if(q->front==q->rear)
		return 1;
	else
		return 0;
}

int in_seqqueue(datatype data,seq_pqueue q)
{
	if(is_full_seqqueue(q))
	{
		printf("sequeue is full!\n");
		return 0;
	}
	q->rear=(q->rear+1)%MAXSIZE;
	q->data[q->rear]=data;
	return 1;
}

int out_seqqueue(seq_pqueue q,datatype *p)
{
	if(is_empty_seqqueue(q))
	{
		printf("seqqueue is empty!\n");
		return 0;
	}
	q->front=(q->front+1)%MAXSIZE;
	*p = q->data[q->front];

	return 1;
}

void show_seqqueue(seq_pqueue q)
{
	int i;
	int j=0;
	if(is_empty_seqqueue(q))
		return;
	else
	{
		for(i=((q->front+1)%MAXSIZE);i!=(q->rear+1);i=(i+1)%MAXSIZE)
		{
			j++;
			printf("%d ",q->data[i]);
		}
		puts("");
		printf("%d\n",j);
	}
}
		