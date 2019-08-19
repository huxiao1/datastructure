#include "sqstack.h"
int main()
{
	sqstack *s;
	int n=10;
	s=stack_create(n);
	stack_push(s,1);
	stack_push(s,2);
	stack_push(s,3);
	stack_push(s,4);

	while(!stack_empty(s))
	{
		printf("%d",stack_pop(s));
	}
	
	puts("");
	free(s->data);
	s->data=NULL;
	free(s);
	s=NULL;
	return 0;
}


