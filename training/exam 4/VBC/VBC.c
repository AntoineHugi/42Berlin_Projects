#include "VBC.h"

int accept(char **input, char c)
{
	if (**input == c)
	{
		(*input)++;
		return 1;
	}
	return 0;
}

int expect(char **input, char c)
{
	if (accept(input, c))
		return 1;
	unexpected(**input);
	return 0;
}

void	unexpected(char c)
{
	if (c)
		printf("unexpected token : %c\n", c);
	else
		printf("unexpected end of line\n");
}

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
	if (*input)
	{
		free_tree(root);
		unexpected(*input);
		return (1);
	}
	if (root)
	{
		int result = evaluate(root);
		printf("Result: %d\n", result);
		free_tree(root);
		return 0;
	}
	else
		return (1);
}