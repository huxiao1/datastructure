#include "linkqueue.h"

int main()
{

	link_pqueue q;
	int ret;
	datatype data,a;
	init_linkqueue(&q);

	while(1)
	{
		printf("输入整数入队,输入字母出队\n");
		printf("input:");
		ret=scanf("%d",&data);
		if(ret==1)
		{
			if(in_linkqueue(data,q))
				show_linkqueue(q);
		}
		else
		{
			if(out_linkqueue(q,&a))
			{
				printf("out: %d\n",a);
				show_linkqueue(q);
			}
			while(getchar()!='\n');
		}
	}
	
	return 0;

}