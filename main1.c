#include <stdio.h>
#include "isort.h"

int main()
{
	int arr[SIZE];
	for (int j = 0; j < SIZE; j++)
	{
		printf("enter %d num:", j);
		scanf("%d", &*(arr+j));
	}
	printf("\n");
	insertion_sort(arr, SIZE);
	printf("after the sortion\n\n");
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