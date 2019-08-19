#include<stdio.h>
#include<stdlib.h>
#include"seqlist.h"
int main(int argc,const char *argv[])
{
	int i=0;
	int tmp;
	seqlist_t *L=NULL;
	seqlist_t  *Lb=NULL;

	L=create_seqlist();


	Lb = (seqlist_t *)malloc(sizeof(seqlist_t));
	if(Lb == NULL)
	{
		puts("mo memory");
		return -1;
	}
	Lb->last = -1;
	/*
	for(i=0;i<=4;i++)
		insert_seqlist(L,i,0);
	printf("seqlist L length is %d\n",get_length_seqlist(L));
	show_seqlist(L);
	puts("===================================================");
	puts("search data = 3");
	printf("data = 3 pos is %d\n",search_seqlist(L,3));
	printf("seqlist L length is %d\n",get_length_seqlist(L));
	show_seqlist(L);
	puts("===================================================");
	puts("delete data=3");
	delete_seqlist(L,search_seqlist(L,3));
	printf("seqlist L length is %d\n",get_length_seqlist(L));
	show_seqlist(L);
	puts("===================================================");
	puts("chang data[2] = 99");
	change_seqlist(L,99,2);
	printf("seqlist L length is %d\n",get_length_seqlist(L));
	show_seqlist(L);
	puts("===================================================");
		*/
	puts("delete repeat elements:");
	puts("input three number for L:");
	for(i=0;i<3;i++)
	{
		scanf("%d",&tmp);
		insert_seqlist(L,tmp,i);
	}
	delete_repeat(L);
	show_seqlist(L);
	puts("===================================================");
	puts("append:");
	puts("input three number for Lb:");
	for(i=0;i<3;i++)
	{
		scanf("%d",&tmp);
		insert_seqlist(Lb,tmp,i);
	}
	append_seqlist(L,Lb);
	show_seqlist(L);
	puts("===================================================");
	clear_seqlist(L);
	

	return 0;
}