#ifndef _SQSTACK_H_
#define _SQSTACK_H_
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct{
		datatype * data;
		int maxlen;
		int top;
}sqstack;

extern sqstack * stack_create(int len);
extern int stack_empty(sqstack * s);
extern void stack_clear(sqstack *s);
extern int stack_full(sqstack *s);
extern int stack_push(sqstack *s,datatype value);
extern datatype stack_pop(sqstack *s);
extern datatype stack_top(sqstack *s);

#endif