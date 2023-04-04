#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _node {
	int data;
	struct _node *next;
} node;

typedef struct _stack {
	node *cur;
	node *head;
	int top;
} stack;

void init(stack *st) {
	st -> head = NULL;
	st -> cur = NULL;
	st -> top = 0;
}

void push(stack *st, int data) {
	node *new = (node*)malloc(sizeof(node));

	new -> data = data;
	new -> next = NULL;
	if(st -> top == 0)
	{
		st -> head = new;
		st -> cur = new;
	}
	else
	{
		st -> cur -> next = new;
		st -> cur = new;
	}
	st -> top++;	
}

int pop_nge(stack *st/*, int total_num, int *arr*/)
{
	node *start = st -> cur;
	int nge;
	int max;
/*
	for(int i = total_num - 1; i != 0; i--)
	{

		if(arr[i])
	}
*/
	while(st -> cur != NULL)
	{
		if(start -> data < st -> cur -> data)
		{
			nge = st -> cur -> data;
			if(start -> next != NULL)  
			{
				st -> cur = start -> next;
			}
			return nge;
		}
		st -> cur = st -> cur -> next; 
	}
	if(start -> next != NULL)  
	{
		st -> cur = start -> next;
	}
	return -1;
}

char num_ch[100000010];

int main()
{
	int j, k = 0;
	int n;
	int number;
	//int *arr;
	char num[1000010];
	stack *st = (stack*)malloc(sizeof(stack));
	
	init(st);
	scanf("%d", &n);
	getchar();
	//arr = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		push(st, number);
	}
	st -> cur = st -> head;
	for(int i = 0; i < n; i++)
	{
		printf("%d ", pop_nge(st));
	}
	return 0;	
}
