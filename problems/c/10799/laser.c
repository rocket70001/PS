#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100010 

typedef struct _node {
	char data;
	struct _node *prev;
} node;

typedef struct _stack {
	int top_num;
	node *top;
} stack;

void init(stack *st)
{
	st -> top_num = 0;
	st -> top = NULL;
}

void push(stack *st, char data) {
	if(st -> top_num == MAX)
		return ;
	node *new = (node*)malloc(sizeof(node));

	new -> data = data;
	new -> prev = st -> top;
	st -> top = new;
	st -> top_num++;
}

void pop(stack *st)
{
	if(st -> top_num == 0)
		return ; 
	node *del;
	del = st -> top;
	st -> top = st -> top -> prev;
	st -> top_num--;	
}

int main()
{
	char map[100010];
	int laser = 0;
	int iron;
	stack *st;

	fgets(map, 100010, stdin);
	map[strlen(map) - 1] = '\0';
	init(st);
	for(int i = 0; i < strlen(map) - 1; i++)
	{
		if(map[i] == '(' && map[i + 1] != ')')
		{
			push(st, '(');
			iron++;
		}
		else if(map[i] == '(' && map[i + 1] == ')')
		{
			laser++;	
		}
	}
	
}
