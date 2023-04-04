#include<stdio.h>

void sort_selection(int arr[], int size)
{
	int max_idx;
	int tmp;

	for(int i = 0; i < size - 1; i++)
	{
		max_idx = i;
		for(int j = i + 1; j < size; j++)
		{
			if(arr[max_idx] > arr[j])
				max_idx = j;
		}
		tmp = arr[i];
		arr[i] = arr[max_idx];
		arr[max_idx] = tmp;
	}
}

int main()
{
	int arr[5];
	int sum;
	
	sum = 0;
	for(int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sort_selection(arr, 5);
	printf("%d\n", sum/5);
	printf("%d", arr[2]);
	return 0;
}
