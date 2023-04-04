#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int order;
	struct _node *next;
	struct _node *prev;
} node;

typedef struct _list {
	node *cur;
	node *tail;
	int total;
} list;

void init(list *li)
{
	li -> cur = NULL;
	li -> tail = NULL;
	li -> total = 0;
}

void insertR(list *li, int data)
{
	node *new_node = (node*)malloc(sizeof(node));

	new_node -> order = data; 
	if(li -> total == 0)
	{
		new_node -> prev = new_node;
		new_node -> next = new_node;
		li -> cur = new_node;
		li -> tail = new_node;
	}
	else if(li -> total == 1)
	{
		new_node -> prev = li -> tail;
		new_node -> next = li -> tail;
		li -> cur = new_node;
		li -> tail -> prev = new_node;
		li -> tail -> next = new_node;
	}
	else
	{
		new_node -> prev = li -> cur;
		new_node -> next = li -> tail;
		li -> cur -> next = new_node;
		li -> tail -> prev = new_node;
		li -> cur = new_node;
	}
	li -> total++;
}

void move_cur_R(list *li)
{
	if(li -> total == 1)
		return ;
	li -> cur = li -> cur -> next;
}

int pop_in_order(list *li, int times)
{
	node *pop_node;
	int pop_int; 

	if(li -> total == 0)
		return -1;
	for(int i = 1; i < times; i++)
		move_cur_R(li);
	pop_node = li -> cur;
	pop_int = li -> cur -> order;
	li -> cur -> prev -> next = li -> cur -> next;
	li -> cur -> next -> prev = li -> cur -> prev;
	if(pop_node == li -> tail)
	{
		if(li -> total == 1)
			li -> tail = NULL;
		else
		{	
			li -> tail = li -> cur -> next;
			li -> tail -> next = li -> cur -> next -> next;
			li -> tail -> prev = li -> cur -> prev;
		}
	}
	li -> total--;
	li -> cur = li -> cur -> next;
	free(pop_node);
	return pop_int;
}

int main()
{
	int n;
	int times;
	list *circle = (list*)malloc(sizeof(list));

	scanf("%d %d", &n, &times);
	getchar();
	init(circle);
	for(int i = 1; i < n + 1; i++)
	{
		insertR(circle, i);	
	}
	circle -> cur = circle -> tail;
	printf("<");
	for(int i = 0; i < n - 1; i++)
	{
		printf("%d, ", pop_in_order(circle, times));	
	}
	printf("%d>", pop_in_order(circle, times));	
	free(circle);
}
