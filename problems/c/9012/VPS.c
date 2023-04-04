#include <stdio.h>

#define ps_len 52

char *check_VPS(char *str)
{
	int i = 0;
	int ps = 0;

	while(str[i] != '\0')
	{
		if(str[i] == '(')
			++ps;
		else if(str[i] == ')')
			--ps;
		if(ps == -1)
			return "NO\n";
		i++;
	}
	if(ps == 0)
		return "YES\n";
	return "NO\n";
}

int main(void)
{
	int t;
	char ps[ps_len];

	scanf("%d", &t);
	getchar();
	for(int i = 0; i < t; i++)
	{
		fgets(ps, ps_len, stdin);
		printf("%s", check_VPS(ps));
	}
}
	
