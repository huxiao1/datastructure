#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"


linklist list_create()
{
	linklist H;
	H=(linklist)malloc(sizeof(listnode));
	if(H==NULL)
	{
		puts("malloc failed!");
		return H;
	}
	H->data=0;
	H->next=NULL;
	return H;
}

void list_show(linklist H)
{
	while(H->next){
		printf("%d ",H->next->data);
		H=H->next;
	}
	puts(" ");
}

//头插法
int list_head_insert(linklist H,datatype value)
{
	linklist p;
	p = (linklist)malloc(sizeof(listnode));
	if(p==NULL)
	{
		puts("malloc failed");
		return -1;
	}
	p->data=value;
	p->next=H->next;
	H->next=p;
	return 0;
}

//尾插法
int list_tail_insert(linklist H)
{
	linklist r,p;
	datatype value;
	r=H;
	while(1)
	{
		puts("input a number (-1 exit)");
		scanf("%d",&value);
		if(value==-1)
			break;
		
		p=(linklist)malloc(sizeof(listnode));
		if(p==NULL)
		{
			puts("malloc failed!");
			return -1;
		}
		p->data=value;
		p->next=NULL;

		r->next=p;
		r=r->next;
		//r=p;
	}
	return 0;
}

//中插法
int list_insert(linklist H,int pos,datatype value)
{
	linklist p,q;
	if(pos==0)
	{
		p=H;
	}
	else{
		p=list_get(H,pos-1);
	}

	if(p==NULL)
	{
		printf("para is invalid\n");
		return -1;
	}
	else{
		if((q=(linklist)malloc(sizeof(listnode)))==NULL)
		{
			printf("malloc faile\n");
			return -1;
		}
	}
	q->data=value;
	q->next=p->next;
	p->next=q;
	return 0;
}


linklist list_get(linklist H,int pos)
{
	linklist p=H;
	int i=-1;
	if(pos<0){
		printf("position is invalid:<0\n");
		return NULL;
	}
	while(p->next && i<pos){
		p=p->next;
		i++;
	}
	if(i==pos)
		return p;
	else{
		printf("position is out of range:<0\n");
		return NULL;
	}

}

linklist list_locate(linklist H,datatype value)
{
	linklist p = H->next;

	while(p&&p->data!=value)
	{
		p=p->next;
	}
	
	if(p)
		return p;
	else
		return NULL;
}

int list_delete(linklist H,int pos)
{
	linklist p,q;
	if(pos == 0)
	{
		p=H;
	}
	else{
		p=list_get(H,pos-1);
	}

	if(p == NULL || p->next==NULL){
		printf("para is invalid\n");
		return -1;
	}
	q=p->next;
	p->next=q->next;
	free(q);
	q=NULL;
	return 0;
}

void list_reverse(linklist H)
{
	linklist p,q;
	p=H->next;
	H->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		q->next=H->next;  //体现出之前定义H->next=NULL的重要性
		H->next=q;
	}
}

int list_order_insert(linklist H,datatype value)
{
	linklist p,q;
	if((p=(linklist)malloc(sizeof(listnode)))==NULL)
	{
		printf("malloc failed\n");
		return -1;
	}
	p->data=value;
	q=H;
	while(q->next && (q->next->data < value))
	{
		q=q->next;
	}
	p->next=q->next;
	q->next=p;
	return 0;
}

void list_sort(linklist H)
{
	linklist q,p,r;
	
	p=H->next;
	H->next=NULL;
	
	while(p)
	{
		q=p;
		p=p->next;  //***
		r=H;
		while(r->next && r->next->data < q->data)
		{
			r=r->next;
		}
		q->next=r->next;
		r->next=q;
	}
}

linklist yuesefu_create()
{
	linklist H,r,p;
	int n,i;
loop:
	printf("please input n:");
	scanf("%d",&n);
	if(n<0){
		printf("n should be > 0\n");
		goto loop;
	}

	H=(linklist)malloc(sizeof(listnode));
	if(H==NULL)
	{
		puts("malloc failed!");
		return NULL;
	}
	H->data=1;
	H->next=H;
	r=H;
	
	for(i=2;i<=n;i++)
	{
		if((p=(linklist)malloc(sizeof(listnode)))==NULL)
		{
			puts("malloc failed!");
			return NULL;
		}
		p->data=i;
		r->next=p;
		r=p;
	}
	p->next=H;
	return H;
}

void yuesefu_show(linklist H)
{
	linklist p=H;
	while(p->next!=H){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d",p->data);
	puts(" ");
}

void yuesefu(linklist H,int k,int m)
{
	linklist r,p;
	int i;
	r=H;
	while(r->next->data!=k)
	{
		r=r->next;
	}
	printf("k=%d\n",k);
	while(r->next!=r){
		for(i=0;i<m-1;i++)
			r=r->next;
		p=r->next;
		r->next=p->next;
		printf("%d ",p->data);
		free(p);
		p=NULL;
	}
	printf("%d\n",r->data);
	free(r);
	r=NULL;
}

void deleteall(linklist H)
{
	linklist p,q;
	p=H;
	if (H == NULL) //链表为空无需处理
		return;
	while(p->next!=NULL)
	{
		q=p->next;
		p->next=p->next->next;
		free(q);
	}
	free(p);
	H=NULL;
}
