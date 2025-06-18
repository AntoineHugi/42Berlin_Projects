#include "VBC.h"

// Skip whitespace
void skip_spaces(char **expr)
{
	while (**expr == ' ')
		(*expr)++;
}

// Parse parenthesis: numbers or parenthesized expression
node *parse_parenthesis(char **expr)
{
	skip_spaces(expr);
	if (**expr == '(')
	{
		(*expr)++; // skip '('
		node *n = parse_add(expr);
		skip_spaces(expr);
		if (**expr == ')')
			(*expr)++;
		return n;
	}
	if (isdigit(**expr))
	{
		int value = 0;
		while (isdigit(**expr))
		{
			value = value * 10 + (**expr - '0');
			(*expr)++;
		}
		node *n = (node *)malloc(sizeof(node));
		n->type = VAL;
		n->val = value;
		n->L = NULL;
		n->R = NULL;
		return n;
	}
	return NULL; // invalid input
}

// Parse multi: factors connected by '*'
node *parse_multi(char **expr)
{
	node *left = parse_parenthesis(expr);
	skip_spaces(expr);
	while (**expr == '*')
	{
		(*expr)++; // skip '*'
		node *right = parse_parenthesis(expr);
		node *parent = (node *)malloc(sizeof(node));
		parent->type = MULTI;
		parent->L = left;
		parent->R = right;
		left = parent;
		skip_spaces(expr);
	}
	return left;
}

// Parse expression: terms connected by '+'
node *parse_add(char **expr)
{
	node *left = parse_multi(expr);
	skip_spaces(expr);
	while (**expr == '+')
	{
		(*expr)++; // skip '+'
		node *right = parse_multi(expr);
		node *parent = (node *)malloc(sizeof(node));
		parent->type = ADD;
		parent->L = left;
		parent->R = right;
		left = parent;
		skip_spaces(expr);
	}
	return left;
}
