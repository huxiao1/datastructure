#include "sqstack.h"

sqstack * stack_create(int len)
{
	sqstack *s;
	s=(sqstack *)malloc(sizeof(sqstack));
	if(s==NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	s->data=(datatype *)malloc(len * sizeof(datatype));
	if(s->data==NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	s->maxlen=len;
	s->top=-1;

	return s;
}

int stack_empty(sqstack * s)
{
	return (s->top==-1 ?1:0);
}

void stack_clear(sqstack *s)
{
	s->top=-1;
}

int stack_full(sqstack *s)
{
	return (s->top==s->maxlen-1 ? 1:0);
}

int stack_push(sqstack *s,datatype value)
{
	if(s->top==s->maxlen-1)
	{
		printf("stack is full\n");
		return -1;
	}
	s->top++;
	s->data[s->top]=value;
	return 1;
}

datatype stack_pop(sqstack *s)
{
	s->top--;
	return s->data[s->top+1];
}

datatype stack_top(sqstack *s)
{
	return (s->data[s->top]);
}