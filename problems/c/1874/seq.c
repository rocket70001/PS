#include <stdio.h>
#include <stdlib.h>

#define st_size 100001

typedef struct _stack
{
	int nums[st_size];
	int top;
} stack;

void init_st(stack *st)
{
	st -> top = -1;
}

void push(stack *st, int data)
{
	st -> top++;
	st -> nums[st -> top] = data;
}

int peek(stack *st)
{
	return st -> nums[st -> top];
}

int pop(stack *st)
{
	int top;
	
	top = st -> nums[st -> top];
	st -> top -= 1;
	return top;
}

int st_is_empty(stack *st)
{
	if(st -> top == -1)
		return 1;
	return 0;
}
int main(void)
{
	int t;
	int ch_idx = 0;
	int seq[100001];
	stack *st = (stack*)malloc(sizeof(stack));
	char check[st_size * 2];

	scanf("%d", &t);
	getchar();
	init_st(st);
	for(int i = 0; i < t; i++)
	{
		scanf("%d", &seq[i]);
		getchar();
	}
	int i = 0;
	int num = 1;
	while (1) 
	{
		if (i == t)
		{
			check[ch_idx] = '\0';
			break;
		}
		else if (st_is_empty(st) || st -> nums[st -> top] < seq[i]) 
		{
			push(st, num++);
			check[ch_idx++] = '+';
		}
		else if (st -> nums[st -> top] == seq[i])
		{
			pop(st);
			check[ch_idx++] = '-';
			i++;
	    }
		else
		{
			printf("NO\n");
			return 0;
		}
	}	
	ch_idx = 0;
	while(check[ch_idx] != '\0')
	{
		printf("%c\n", check[ch_idx++]); 
	}
	return 0;
}
