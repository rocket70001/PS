#include <stdio.h>

void sort_selection(int arr[], int N)
{
	int tmp;
	int max_idx;

	for(int i = 0; i < N - 1; i++)
	{
		max_idx = i;

		for(int j = i + 1; j < N; j++)
		{
			if(arr[j] < arr[max_idx])
				max_idx = j;
		}
		tmp = arr[i];
		arr[i] = arr[max_idx];
		arr[max_idx] = tmp;
	}
}

int main ()
{
	int N;
	int arr[1100];

	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort_selection(arr, N);
	for(int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
	return 0;
}
