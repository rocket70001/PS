#include <stdio.h>
#include <stdlib.h>
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

void initStack(stack *st)
{
	st -> head = 0;
	st -> numOfData = 0;
}

void push(stack *st, int data)
{	
	node *newNode = 0;
	
	newNode = (node*)malloc(sizeof(node));
	newNode -> data = data;
	newNode -> next = st -> head;
	st -> head = newNode;
	st -> numOfData++;
}

int pop(stack *st)
{
	int output;
	node *popNode = 0;
	
	if(st -> head == 0)
	{
		printf("%d\n", -1);
		return -1;
	}
	popNode = st -> head; 	
	output = popNode -> data;
	st -> head = st -> head -> next;	
	st -> numOfData--;
	free(popNode);
	printf("%d\n", output);
	return output;
}

int size(stack *st)
{
	if(st -> head == 0)
	{
		printf("%d\n", 0);
		return 0;
	}
	printf("%d\n", st -> numOfData);
	return st -> numOfData;
}

void stIsEmpty(stack *st)
{	
	if(st -> head == 0)
	{
		printf("%d\n", 1);
	}
	else 
		printf("%d\n", 0);
}

void top(stack *st)
{
	if(st -> head == 0)
	{
		printf("%d\n", -1);
		return ;
	}
	printf("%d\n", st -> head -> data);
}

void resetOrder(char *order)
{
	int i = 0;

	while(order[i] != '\0')
	{
		order[i] = '\0';
		i++;
	}
}

void readOrder(char *order, stack *st)
{
	int num = 0;
	int j = 0;
	char *atoiDoesntWorkWithArr = malloc(sizeof(char) * 100);

	if(strncmp("top", order, 3) == 0)
		top(st);
	if(strncmp("size", order, 4) == 0)
		size(st);
	if(strncmp("empty", order, 5) == 0)
		stIsEmpty(st);
	if(strncmp("pop", order, 3) == 0)
		pop(st);
	if(strncmp("push ", order, 5) == 0)
	{
		for(int i = 5; i < 99; i++)
		{
			atoiDoesntWorkWithArr[j] = order[i];
			j++;
		}
		num = atoi(atoiDoesntWorkWithArr);
		resetOrder(atoiDoesntWorkWithArr);
		push(st, num);
	}
}

int main(void)
{
	int n;
	stack *st = malloc(sizeof(stack));
	char order[100];

	scanf("%d", &n);
	initStack(st);
	for(int i = 0; i <= n; i++)
	{
		fgets(order, 100, stdin);
		readOrder(order, st);
		resetOrder(order);
	}
	free(st);
	return 0;
}
