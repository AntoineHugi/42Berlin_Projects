#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
	enum { ADD, MULTI, VAL } type;
	int val;
	struct node *L;
	struct node *R;
    } node;

node *parse_add(char **expr);
node *parse_multi(char **expr);
node *parse_parenthesis(char **expr);
void skip_spaces(char **expr);
int evaluate(node *n);
void free_tree(node *n);