#include "linkstack.h"

int main()
{
	linklist s;
	s=linkstack_create();
	linkstack_push(s,1);
	linkstack_push(s,2);
	linkstack_push(s,3);
	linkstack_push(s,4);
	while(!linkstack_empty(s))
	{
		printf("%d",linkstack_pop(s));
	}
	puts("");
	linkstack_free(s);
	return 0;
}