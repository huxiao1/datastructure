#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdio.h>
#include <stdlib.h>
typedef char datatype_bt;

typedef struct btreenode{
	datatype_bt data;
	struct btreenode *lchild,*rchild;
}btree_node,*btree_pnode;

extern void create_btree(btree_pnode *T);
extern void pre_order(btree_pnode t);
extern void mid_order(btree_pnode t);
extern void post_order(btree_pnode t);
extern void level_order(btree_pnode t);
extern void unpre_order(btree_pnode t);
extern void travel(char const *str,void (*pfun)(btree_pnode),btree_pnode t);

#endif