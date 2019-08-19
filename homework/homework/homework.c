#include "homework.h"
dlistnode * dlist_create()
{
	dlistnode * H;

	if((H=(dlistnode *)malloc(sizeof(dlistnode)))==NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}

	H->prior=H;
	H->next=H;

	return H;
}

dlistnode *list_create()
{
	dlistnode *H,*r,*p;
	int n,i;
loop:
	printf("please input n:");
	scanf("%d",&n);
	if(n<0){
		printf("n should be > 0\n");
		goto loop;
	}

	H=(dlistnode *)malloc(sizeof(dlistnode));
	if(H==NULL)
	{
		puts("malloc failed!");
		return NULL;
	}
	H->next=H;
	r=H;
	
	for(i=2;i<=n;i++)
	{
		if((p=(dlistnode *)malloc(sizeof(dlistnode)))==NULL)
		{
			puts("malloc failed!");
			return NULL;
		}
		p->data=i-1;
		r->next=p;
		r=p;
	}
	p->next=H;
	return H;
}