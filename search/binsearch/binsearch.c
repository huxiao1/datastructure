#include<stdio.h>
#define N 12
int binsearch(int *a,int key);

int main()
{
	int a[N] = {3,12,18,20,32,55,60,68,80,86,90,100};
	int i,key;
	char ch;
	
	while(1){
		printf("please input key:");
		scanf("%d",&key);
		i=binsearch(a,key);
		if(i == -1)
		{
			printf("search error!\n");
		}
		else
		{
			printf("search %d at %d\n",key,i);
		}
		printf("continue?(Y/y):");
		while(getchar()!='\n');
		scanf("%c",&ch);
		if(ch=='y' || ch=='Y')
			continue;
		else
			break;
	}
	return 0;
}


int binsearch(int *a,int key)
{
	int high,low,mid;
	low=0;
	high=N-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
			return mid;
		else if(key<a[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}