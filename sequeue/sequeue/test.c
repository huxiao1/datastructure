#include "sequeue.h"

int main()
{
	
	//int a;
	seq_pqueue q;
	init_seqqueue(&q);
	in_seqqueue(1,q);
	in_seqqueue(2,q);
	in_seqqueue(3,q);
	in_seqqueue(4,q);
	in_seqqueue(5,q);
	show_seqqueue(q);
	//out_seqqueue(q,&a);
	//printf("%d\n",a);
	return 0;
	
	/*
	seq_pqueue q;
	int ret;
	datatype data,a;
	init_seqqueue(&q);
	
	in_seqqueue(1,q);
	in_seqqueue(2,q);
	in_seqqueue(3,q);
	in_seqqueue(4,q);
	in_seqqueue(5,q);
	show_seqqueue(q);

	while(1)
	{
		printf("输入整数入队,输入字母出队\n");
		printf("input:");
		ret=scanf("%d",&data);
		if(ret==1)
		{
			if(in_seqqueue(data,q))
				show_seqqueue(q);
		}
		else
		{
			if(out_seqqueue(q,&a))
			{
				printf("out: %d\n",a);
				show_seqqueue(q);
			}
			while(getchar()!='\n');
		}
	}
	*/
	return 0;

}