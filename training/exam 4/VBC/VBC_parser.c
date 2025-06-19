#include "VBC.h"

// Parse parenthesis: numbers or parenthesized expression
node *parse_parenthesis(char **input)
{
	if (accept(input, '('))
	{
		node *n = parse_add(input);
		if (!n || !expect(input, ')'))
		{
			if (n)
				free_tree(n);
			return NULL;
		}
		return n;
	}

	if (isdigit(**input))
	{
		int value = 0;
		while (isdigit(**input))
		{
			value = value * 10 + (**input - '0');
			(*input)++;
		}
		node *n = malloc(sizeof(node));
		n->type = VAL;
		n->val = value;
		n->L = n->R = NULL;
		return n;
	}

	unexpected(**input);
	return NULL;
}

node *parse_multi(char **input)
{
	node *left = parse_parenthesis(input);
	if (!left)
		return NULL;

	while (accept(input, '*'))
	{
		node *right = parse_parenthesis(input);
		if (!right)
		{
			free_tree(left);
			return NULL;
		}
		node *parent = malloc(sizeof(node));
		parent->type = MULTI;
		parent->L = left;
		parent->R = right;
		left = parent;
	}
	return left;
}

node *parse_add(char **input)
{
	node *left = parse_multi(input);
	if (!left)
		return NULL;
	while (accept(input, '+'))
	{
		node *right = parse_multi(input);
		if (!right)
		{
			free_tree(left);
			return NULL;
		}
		node *parent = malloc(sizeof(node));
		parent->type = ADD;
		parent->L = left;
		parent->R = right;
		left = parent;
	}
	return left;
}
