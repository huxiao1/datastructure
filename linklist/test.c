#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

int main()
{
	int choose;
	printf("if yuesefu cin 1:");
	scanf("%d",&choose);
	if(choose==1)
	{
		int k=3,m=4;
		linklist H;
		H=yuesefu_create();
		yuesefu_show(H);
		yuesefu(H,k,m);
		return 0;
	}
	else
	{
		int n,choose1;
		int postion,data;
		linklist H,p;
		H = list_create();
		list_tail_insert(H);
		list_show(H);
	
		while(1)
		{
			printf("\n");
			printf("1.search by pos\n");
			printf("2.search by value\n");
			printf("3.insert\n");
			printf("4.delete\n");
			printf("5.reverse\n");
			printf("6.show\n");
			printf("7.insert2\n");
			printf("8.sort\n");
			printf("9.在一个有序的链表中，插入一个元素，链表依然有序\n");
			printf("10.deleteall\n");
			printf("11.exit\n");
			printf("please search the function");
			scanf("%d",&choose1);

			switch(choose1)
			{
			case 1:
				{
					printf("please input position:");
					scanf("%d",&n);
					if(p=list_get(H,n))
						printf("node data:%d\n",p->data);
					break;
				}
			case 2:
				{
					printf("please input value:");
					scanf("%d",&n);
					if(p=list_locate(H,n))
						printf("found:%d\n",p->data);
					else
						printf("not found\n");
					break;
				}
			case 3:
				{
					printf("input position and data:");
					scanf("%d %d",&postion,&data);
					list_insert(H,postion,data);
					list_show(H);
					break;
				}
			case 4:
				{
					printf("input a pos to delete:");
					scanf("%d",&n);
					list_delete(H,n);
					list_show(H);
					break;
				}
			case 5:
				{
					list_reverse(H);
					list_show(H);
					break;
				}
			case 6:
				list_show(H);
				break;
			case 7:
				{
					list_order_insert(H,6);
					list_show(H);
					break;
				}
			case 8:
				{
					list_sort(H);
					list_show(H);
					break;
				}
			case 9:
				{
					printf("input the data to insert:");
					scanf("%d",&n);
					list_order_insert(H,n);
					list_show(H);
					break;
				}
			case 10:
				{
					deleteall(H);
					//list_show(H);
					break;
				}
			case 11:
				return 0;
			}
		}
		}
	return 0;
}