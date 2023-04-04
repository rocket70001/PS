#include <stdio.h>

typedef int (*inputPriority)(int comp1, int comp2);

typedef struct _heap
{
	inputPriority *priority;
	int size;
	int heapArr[10000000];
} heap;

void initHeap(heap *h, inputPriority p)
{
	h -> size = 0;
	h -> priority = &p;
}

int HIsEmpty(heap *h)
{
	if(h -> size == 0)
		return 1;
	else
		return 0;
}

int getParentIdx(int idx)
{
	return idx / 2;
}

int getLChildIdx(int idx)
{
	return idx * 2;
}

int getRChildIdx(int idx)
{
	return getLChildIdx(idx) + 1;
}

int getPriorChildIdx(heap *h, int idx)
{
	if(getLChildIdx(idx) > h -> size)
		return 0;
	else if(getLChildIdx(idx) == h -> size)
		return getLChildIdx(idx);

	else
	{
		if(h -> priority(h -> heapArr[getLChildIdx(idx)],
					h -> heapArr[getRChildIdx(idx)]) < 0)
			return getRChildIdx(idx);
		else
			return getLChildIdx(idx);
	}
}

void HInsert(heap *h, int data)
{
	int idx = h -> size + 1;

	while(idx != 1)
	{
		if(h -> priority(data, h -> heapArr[getParentIdx(idx)]) > 0)
		{
			h -> heapArr[idx] = h -> heapArr[getParentIdx(idx)];
			idx = getParentIdx(idx);
		}
		else
		{
			break;
		}
	}

	h -> heapArr[idx] = data;
	h -> size += 1;
}

int HDelete(heap *h)
{
	int rootData = h -> heapArr[1];
	int lastElem = h -> heapArr[h -> size];
	int parentIdx = 1;
	int childIdx;

	while(childIdx == getPriorChildIdx(h, parentIdx))
	{
		if(h -> priority(lastElem, h -> heapArr[childIdx]) >= 0)
			break;
		h -> heapArr[parentIdx] = h -> heapArr[childIdx];
		parentIdx = childIdx;
	}
	h -> heapArr[parentIdx] = lastElem;
	h -> size -= 1;
	return rootData;
}

int setPriority(int num1, int num2)
{
	return num2 - num1;
}

int main(void)
{
	int n;
	int a;
	heap heapSort;

	initHeap(&heapSort,setPriority);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		HInsert(&heapSort, a);
	}
	while(!HIsEmpty(&heapSort))
		printf("%d\n", HDelete(&heapSort)); 
	return 0;
}
