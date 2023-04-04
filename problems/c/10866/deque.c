#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *next;
	struct _node *prev;
} node;

typedef struct _deque {
	node *front;
	node *rear;
	int num_deque;
} deque;

void init_deq(deque *deq)
{
	deq -> front = NULL;
	deq -> rear = NULL;
	deq -> num_deque = 0;
}

void put_front(deque *deq, int data)
{
	node *new = (node*)malloc(sizeof(node));

	new -> data = data;
	if(deq -> num_deque == 0)
	{
		new -> next = new;
		new -> prev = new;
		deq -> front = new;
		deq -> rear = new;
	}
	else 
	{
		new -> next = deq -> front;
		new -> prev = NULL;
		deq -> front -> prev = new;
		new -> next = deq -> front;
		deq -> front = new;
	}
	deq -> num_deque++;
}

void put_rear(deque *deq, int data)
{
	node *new = (node*)malloc(sizeof(node));

	new -> data = data;
	if(deq -> num_deque == 0)
	{
		new -> next = new;
		new -> prev = new;
		deq -> front = new;
		deq -> rear = new;
	}
	else 
	{
		new -> next = NULL;
		new -> prev = deq -> rear;
		deq -> rear -> next = new;
		new -> prev = deq -> rear;
		deq -> rear = new;
	}
	deq -> num_deque++;
}

void pop_front(deque *deq) {
	if(deq -> num_deque == 0)
	{
		printf("%d\n", -1);
		return ;
	}
	node *del = deq -> front;
	deq -> front = deq -> front -> next;
	printf("%d\n", del -> data);
	deq -> num_deque--;
	free(del);
}

void pop_rear(deque *deq) {
	if(deq -> num_deque == 0)
	{
		printf("%d\n", -1);
		return ;
	}
	node *del = deq -> rear;
	deq -> rear = deq -> rear -> prev;
	printf("%d\n", del -> data);
	deq -> num_deque--;
	free(del);
}

void size(deque *deq)
{
	printf("%d\n", deq -> num_deque);
}

void empty(deque *deq)
{
	if(deq -> num_deque == 0)
		printf("%d\n", 1);
	else
		printf("%d\n", 0);
}

void front(deque *deq)
{
	if(deq -> num_deque == 0)
	{
		printf("%d\n", -1);
		return ;
	}
	printf("%d\n", deq -> front -> data);
}

void back(deque *deq)
{
	if(deq -> num_deque == 0)
	{
		printf("%d\n", -1);
		return ;
	}
	printf("%d\n", deq -> rear -> data);
}

void get_order(deque *deq, char *order)
{
	int x;

	if(strncmp(order, "push_front", 10) == 0)
	{
		scanf("%d", &x);
		put_front(deq, x);	
		return ;
	}
	else if(strncmp(order, "push_back", 9) == 0)
	{
		scanf("%d", &x);
		put_rear(deq, x);
		return ;
	}
	else if(strcmp(order, "pop_front") == 0)
	{
		pop_front(deq);
		return ;
	}
	else if(strcmp(order, "pop_back") == 0)
	{
		pop_rear(deq);
		return ;
	}
	else if(strcmp(order, "size") == 0)
	{
		size(deq);
		return ;
	}
	else if(strcmp(order, "empty") == 0)
	{
		empty(deq);
		return ;
	}
	else if(strcmp(order, "front") == 0)
	{
		front(deq);
		return ;
	}
	else if(strcmp(order, "back") == 0)
	{
		back(deq);
		return ;
	}
}

int main()
{
	int n;
	char order[15];
	deque *deq = (deque*)malloc(sizeof(deque));

	init_deq(deq);
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++)
	{
		scanf("%s", order);
		getchar();
		get_order(deq, order);
	}
	return 0;
}
