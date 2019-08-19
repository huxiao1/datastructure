#include "btree.h"
#include "linkqueue.h"
#include "linkstack.h"
/*
btree_pnode create_btree()
{
	datatype ch;
	btree_pnode q;
	printf("please input a char:");
	scanf("%c",&ch);
	if(ch=='#')
	{
		return NULL;
	}
	else{
		//创建根节点
		q=(btree_pnode)malloc(sizeof(btree_node));
		if(q==NULL)
		{
			perror("malloc failed!\n");
			exit(-1);
		}
		q->data=ch;
		//创建左,右子树
		q->lchild=create_btree();
		q->rchild=create_btree();
	}
}
*/

void create_btree(btree_pnode *t)
{
	datatype_bt ch;
	scanf("%c",&ch);
	if(ch =='#')
	{
		(*t)=NULL;
	}
	else{
		//创建根节点
		(*t)=(btree_pnode)malloc(sizeof(btree_node));
		if(*t==NULL)
		{
			perror("malloc failed!\n");
			exit(-1);
		}
		(*t)->data=ch;
		//创建左,右子树
		create_btree(&(*t)->lchild);
		create_btree(&(*t)->rchild);
	}
}

//先序遍利
void pre_order(btree_pnode t)
{
	if(t!=NULL)
	{
		printf("%c",t->data);
		//先序遍利左子树
		pre_order(t->lchild);
		//先序遍利右子树
		pre_order(t->rchild);
	}
}

//中序遍利
void mid_order(btree_pnode t)
{
	if(t!=NULL)
	{
		//中序遍利左子树
		mid_order(t->lchild);

		printf("%c",t->data);
		//中序遍利右子树
		mid_order(t->rchild);
	}
}

//后序遍利
void post_order(btree_pnode t)
{
	if(t!=NULL)
	{
		//后序遍利左子树
		post_order(t->lchild);
		//后序遍利右子树
		post_order(t->rchild);

		printf("%c",t->data);
	}
}

//层次遍历
void level_order(btree_pnode t)
{
	link_pqueue q;
	init_linkqueue(&q);
	while(t!=NULL)
	{
		printf("%c",t->data);
		if(t->lchild!=NULL)
			in_linkqueue(t->lchild,q);
		if(t->rchild!=NULL)
			in_linkqueue(t->rchild,q);
		if(!is_empty_linkqueue(q))
			out_linkqueue(q,&t);
		else
			break;
	}
}

//非递归先序遍利
void unpre_order(btree_pnode t)
{
	linklist top;
	top=linkstack_create();
	
	while( t!=NULL || !linkstack_empty(top) )
	{
		if(t!=NULL)
		{
			printf("%c",t->data);
			if(t->rchild!=NULL)
			{
				linkstack_push(top,t->rchild);
			}
			t=t->lchild;
		}
		else{
			linkstack_pop(top,&t);
		}
	}
}

void travel(char const *str,void (*pfun)(btree_pnode),btree_pnode t)
{
	printf("%s",str);
	pfun(t);
	printf("\n");
}