#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse_word(char *str, int wordF, int wordL)
{
	char tmp;
	int i = 0;

	while(i <= abs(wordL - wordF) / 2)
	{
		tmp = str[wordL - i];
		str[wordL - i] = str[wordF + i];
		str[wordF + i] = tmp;
		i++;
	}
}

void reverse_str(char *str, int len)
{
	int i = 0;
	int wordF;
	int wordL;

	while(i < len)
	{
		if(str[i] != '\0' && str[i] > 32)
		{
			wordF = i;	
			while(str[i] != '\0' && str[i] > 32)
			{
				i++;	 
			}
			wordL = i - 1;
		}
		reverse_word(str, wordF, wordL);
		i++;
	}
}

void print_str(char *str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	printf("%c", '\n');
}

int main(void)
{
	int t;
	int len;
	char str[2000];

	scanf("%d", &t);
	getchar();
	for(int i = 0; i < t; i++)
	{
		fgets(str, 2000, stdin);
		len = strlen(str);
		if(str[len - 1] == '\n') 
			str[len - 1] = '\0';
		reverse_str(str, len);
		print_str(str);
		//memset(str, 0, sizeof(char)); - fgets null-terminates the string 
	}
	return 0;	
}
