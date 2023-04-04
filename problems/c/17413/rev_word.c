#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *sentence, int s_idx, int e_idx)
{
	char tmp;

	for(int i = 0; i <= (e_idx - s_idx)/2; i++)
	{
		tmp = sentence[s_idx + i];
		sentence[s_idx + i] = sentence[e_idx - i];
		sentence[e_idx - i] = tmp;
	}
}

int main()
{
	char s[100010];
	int s_idx;
	int e_idx;

	fgets(s, 100010, stdin);
	s[strlen(s) - 1] = '\0';
	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i] == '<')
		{
			while(s[i] != '>')
				i++;
		}
		else if(!(s[i] < 33))
		{
			s_idx = i;
			while(s[i] > 33)
			{
				i++;
				if(s[i] == '<')
				{
					break;
				}
			}
			e_idx = i - 1;
			if(s[i] == '<')
				i -= 1;
		reverse(s, s_idx, e_idx);
		}
	}
	printf("%s", s);
	return 0;
}

