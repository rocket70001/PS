#include <stdio.h>

void bubbleSort(int arr[], int size)
{
	int tmp;

	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(arr[j] < arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main(void)
{
	int i, k;
	int scores[1100];

	scanf("%d%d", &i, &k);
	for(int j = 0; j < i; j++)
	{
		scanf("%d", &scores[j]);
	}
	bubbleSort(scores, i);
	printf("%d", scores[k - 1]);
	return 0;
}
