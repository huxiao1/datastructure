#ifndef __SEQUEUE_H__
#define __SEQUEUE_H__

#include <stdio.h>
#include<stdlib.h>
//#include <stdbool.h>

typedef int datatype; 
#define MAXSIZE 10

typedef struct seqqueue{
	datatype data[MAXSIZE];
	int front,rear;
}seq_queue,*seq_pqueue;

//extern seq_pqueue init_seqqueue();
extern void init_seqqueue(seq_pqueue *q);
extern int is_full_seqqueue(seq_pqueue q);
extern int is_empty_seqqueue(seq_pqueue q);
extern int in_seqqueue(datatype data,seq_pqueue q);
extern int out_seqqueue(seq_pqueue q,datatype *p);
extern void show_seqqueue(seq_pqueue q);




#endif

