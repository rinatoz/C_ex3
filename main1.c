#include <stdio.h>
#include "isort.h"

int main()
{
	int arr[SIZE];
	for (int j = 0; j < SIZE; j++)
	{
		
		scanf("%d", &*(arr+j));
	}
	insertion_sort(arr, SIZE);
	for (int j = 0; j < SIZE; j++)
	{
		if (j < SIZE - 1)
		{
			printf("%d,", *(arr+j));
		}
		else
		{
			printf("%d", *(arr+j));
		}
	}


	return 0;
}
