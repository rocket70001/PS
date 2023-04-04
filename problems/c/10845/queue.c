#include <stdio.h>
#include <stdlib.h>

typedef struct _node 
{
	int data;
	struct _node *next;
} node;

typedef struct _queue
{
	node *head;
	node *tail;
	int num_of_data;
} queue;

void init(queue *que)
{
	que -> head = NULL;
	que -> tail = NULL;
	que -> num_of_data = 0;
}

void push(queue *que, int data) 
{
	node *new_node = (node*)malloc(sizeof(node));

	new_node -> data = data;
	new_node -> next = NULL;
	if(que -> num_of_data == 0)
	{
		que -> head = new_node;
		que -> tail = new_node;
	}
	else if(que -> num_of_data == 1)
	{
		que -> head -> next = new_node;
		que -> tail = new_node;
	}
	else
	{
		que -> tail -> next = new_node;
		que -> tail = new_node;
	}
	que -> num_of_data++;
}

int pop(queue *que)
{
	node *del_node;
	int data;

	if(que -> head == NULL)
	{	
		printf("%d\n", -1);
		return -1;
	}
	
	del_node = que -> head;
	data = que -> head -> data;
	
	que -> head = que -> head -> next;
	que -> num_of_data--;

	free(del_node);
	printf("%d\n", data);
	return data;
}

void size(queue *que)
{
	printf("%d\n", que -> num_of_data);
}

void isQueEmpty(queue *que)
{
	if(que -> num_of_data == 0)
		printf("%d\n", 1);
	else
		printf("%d\n", 0);
}

void front(queue *que)
{
	if(que -> num_of_data == 0)
		printf("%d\n", -1);
	else
		printf("%d\n", que -> head -> data);
}

void back(queue *que)
{
	if(que -> num_of_data == 0)
		printf("%d\n", -1);
	else
		printf("%d\n", que -> tail -> data);
}

void getOrder(queue *que)
{
	char order[20];
	int num = 0;

	scanf("%s", order);
	switch(order[1])
	{
	case 'u': 
		scanf("%d", &num);
		push(que, num);
		break;
	case 'o':
		pop(que);
		break;
	case 'i':
		size(que);
		break;
	case 'm':
		isQueEmpty(que);
		break;
	case 'r':
		front(que);
		break;
	case 'a':
		back(que);
		break;
	default:
		break;
	}
}

int main()
{
	int n;
	queue *que = (queue*)malloc(sizeof(queue));
	
	init(que);
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++)
	{
		getOrder(que);
	}
	return 0;
}
