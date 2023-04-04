#include <stdio.h>
#include <string.h>

typedef struct _node
{
	int data;
	struct _node *next;
}node;

typedef struct _stack
{
	node *head;
	int numOfData;
}stack;

void init(stack *st)
{
	st -> head = NULL;
	st -> numOfData = 0;
}

void push(stack *st, int data)
{
	node *newNode = (node*)malloc(sizeof(node));

	newNode -> data = data;
	newNode -> next = st -> head;
	newNode -> numOfData++;

	st -> head = newNode;
}

int pop(stack *st)
{
	int num;
	node *tmp;

	if(st -> head == '\n')
		printf("-1");
	num = st -> head -> data;
	tmp = st -> head;

	st -> head = st -> head -> next;
	st -> numOfData--;
	free(tmp);
	return num;
}

void size(stack *st)
{
	printf("%d", st -> numOfData);
}

void empty(stack *st)
{
	if(st -> head == '\0')
		printf("1");
	else
		printf("0");
}

void top(stack *st)
{
	if(st -> head == '\0')
		printf("-1");
	else
		printf("%d", st -> head -> data);
}

void readOrder(char *order, stack *st)
{
	int num;

	if(strcmp("top", *order) == 0)
		top(*st);
	if(strcmp("size", *order) == 0)
		size(*st);
	if(strcmp("empty", *order) == 0)
		empty(*st);
	if(strcmp("pop", *order) == 0)
		pop(*st);
	if(strncmp("push", *order, 4) == 0)
	{
		num = atoi(*order);
		push(*st, num);
	}
}


int main(void)
{
	int n;
	char *orders = '\0';

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", &orders);
		readOrder(*orders, *st);
		free(orders);
	}
}
