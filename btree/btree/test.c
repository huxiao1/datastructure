#include "btree.h"

int main()
{
	btree_pnode t;
	create_btree(&t);
	printf("pioneer show:");
	pre_order(t);
	puts("");
	printf("mid show:");
	mid_order(t);
	puts("");
	printf("post show:");
	post_order(t);
	puts("");
	printf("level show:");
	level_order(t);
	puts("");
	printf("unpioneer show:");
	unpre_order(t);
	puts("");
	travle("pioneer show:",pre_order,t);
	return 0;
}
//AB#CD###E#FGH##K###