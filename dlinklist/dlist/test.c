#include "dlist.h"

int main()
{
	dlistnode * H,*p;
	int pos,choose,value;
	H = dlist_create();
	dlist_show(H);
	
	
	while(1)
	{
		printf("1.search\n");
		printf("2.insert\n");
		printf("3.show\n");
		printf("4.delete\n");
		printf("8.exit\n");
		printf("input your choose:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				{
					printf("input pos:");
					scanf("%d",&pos);
					p=dlist_get(H,pos);
					if(p)
					{
						printf("%d\n",p->data);	
					}
					break;
				}
			case 2:
				{
					printf("input pos:");
					scanf("%d",&pos);
					printf("input value:");
					scanf("%d",&value);
					dlist_insert(H,value,pos);
					dlist_show(H);
					break;
				}
			case 3:
				dlist_show(H);
				break;
			case 4:
				{
					printf("input pos:");
					scanf("%d",&pos);
					dlist_delete(H,pos);
					dlist_show(H);
					break;
				}
			case 8:
				return 0;
		}
	}
	return 0;
}