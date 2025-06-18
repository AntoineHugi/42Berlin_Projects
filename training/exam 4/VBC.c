#include "VBC.h"

void free_tree(node *n)
{
	if (!n)
		return;
	free_tree(n->L);
	free_tree(n->R);
	free(n);
}

// Evaluate the tree
int evaluate(node *n)
{
	if (n->type == VAL)
		return n->val;
	int lval = evaluate(n->L);
	int rval = evaluate(n->R);
	if (n->type == ADD)
		return lval + rval;
	if (n->type == MULTI)
		return lval * rval;
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char *input = argv[1];
	node *root = parse_add(&input);
	int result = evaluate(root);
	printf("Result: %d\n", result);
	free_tree(root);
	return 0;
}