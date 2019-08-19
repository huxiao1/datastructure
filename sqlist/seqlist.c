#include<stdio.h>
#include<stdlib.h>
#include"seqlist.h"

seqlist_t *create_seqlist(void)
{
	seqlist_t *L=NULL;
	L = (seqlist_t *)malloc(sizeof(seqlist_t));
	if(L == NULL)
	{
		puts("mo memory");
		return NULL;
	}
	L->last = -1;
	return L;
}

void clear_seqlist(seqlist_t *L)
{
	if(L == NULL)
	{
		puts("seqlist_t *L is NULL");
		return ;
	}
	free(L);
	return;
}

int is_empty_seqlist(seqlist_t *L)
{
	if(L == NULL)
	{
		puts("seqlist_t *L is NULL");
		return -1;
	}
	return (L->last == -1);
}

int is_full_seqlist(seqlist_t *L)
{
	if(L == NULL)
	{
		puts("seqlist_t *L is NULL");
		return -1;
	}
	return (L->last == MAXSIZE-1);
}

void set_empty_seqlist(seqlist_t *L)
{
	if(L == NULL)
	{
		puts("seqlist_t *L is NULL");
		return;
	}
	L->last=-1;
	return ;
}

int get_length_seqlist(seqlist_t *L)
{
	if(L == NULL)
	{
		puts("seqlist_t *L is NULL");
		return -1;
	}
	return L->last+1;
}

void show_seqlist(seqlist_t *L)
{
	int i=0;
	if(L == NULL)
	{
		puts("seqlist_t *L is NULL");
		return ;
	}
	for(i=0;i<=L->last;i++)
		printf("L->data[%d]=%d\n",i,L->data[i]);
	return;
}

int insert_seqlist(seqlist_t *L,data_t x,int pos)
{
	int i=0;
	if((is_full_seqlist(L))||(pos<0)||(pos>L->last+1))
	{
		puts("input argv is invalid");
		return -1;
	}
	for(i=L->last;i>=pos;i--)
		L->data[i+1] = L->data[i];
	L->data[pos] = x;
	L->last++;
	return 0;
}

int delete_seqlist(seqlist_t *L,int pos)
{
	int i=0;
	if((pos<0)||(pos>L->last))
	{
		puts("input pos is invalid");
		return -1;
	}
	for(i=pos;i<get_length_seqlist(L);i++)
	{
		L->data[i]=L->data[i+1];
	}
	L->last--;
	return 0;
}

int change_seqlist(seqlist_t *L,data_t x,int pos)
{
	if((pos<0)||(pos>L->last))
	{
		puts("input pos is invalid");
		return -1;
	}
	L->data[pos]=x;
	return 0;
}

int search_seqlist(seqlist_t *L,data_t x)
{
	int i=0;
	for(i=0;i<=L->last;i++)
	{
		if(L->data[i] == x)
			return i;
	}
	return -1;
}

/**********************��ҵ***********************/
int delete_repeat(seqlist_t *L)
{
	int i=0;
	int j=0;
	while(j<get_length_seqlist(L))
	{
		int tmp=L->data[j];
		for(i=j+1;i<get_length_seqlist(L);i++)
		{
			if(tmp==L->data[i])
				delete_seqlist(L,i);
		}
		j++;
	}
	return 0;
}
	
void append_seqlist(seqlist_t *L,seqlist_t *Lb)
{
	int i=0;
//	int j=0;
	
	while(i<get_length_seqlist(Lb))
	{
		if(search_seqlist(L,Lb->data[i])==-1)
		{
			insert_seqlist(L,Lb->data[i],get_length_seqlist(L));
		}
		i++;
	}
}
		












