#include <stdio.h>
#define N 8

void show(int a[]);
void quicksort(int a[],int low,int high);
int quickpass(int a[],int i,int j);

int main()
{
	int a[N]={50,36,66,76,36,12,25,95};
	printf("ԭ��¼����:\n");
	show(a);
	printf("�����������:\n");
	quicksort(a,0,N-1);
	//show(a);
	return 0;
}

void quicksort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = quickpass(a,low,high);   //һ�ο���
		show(a);
		quicksort(a,low,mid-1); //���
		quicksort(a,mid+1,high); //�ұ�
	}
}

int quickpass(int a[],int i,int j)
{
	int tmp;
	tmp=a[i];
	while(i<j)
	{
		while(i<j && tmp<=a[j])
			j--;
		if(i<j)
			a[i]=a[j];
		while(i<j && tmp>=a[i])
			i++;
		if(i<j)
			a[j]=a[i];
	}
	a[j]=tmp;
	return i; 
}


void show(int a[])
{
	int i;
	for(i=0;i<N;i++)
		printf("%d\t",a[i]);
	puts("");
}

