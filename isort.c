#include <stdio.h>
#include "isort.h"

void shift_element(int* arr, int i)
{
	int temp = *(arr + 1), temp1;

	for (int j = 1; j <= i; j++)
	{
		temp1 = *(arr + j + 1);
		*(arr + j + 1) = temp;
		temp = temp1;

	}
	return;
}
void insertion_sort(int* arr, int len)
{
	int i, temp, j;
	int counter = 0;
	for (i = 1; i < len; i++) {
		counter = 0;
		temp = *(arr + i);
		j = i - 1;

		while (j >= 0 && *(arr + j) > temp) {
			counter++;
			j = j - 1;
		}
		shift_element(arr + j, counter);
		*(arr + j + 1) = temp;
	}
}


