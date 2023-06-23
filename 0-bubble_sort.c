#include "sort.h"
#include <stdio.h>
/**
 * @void bubble_sort: that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @a: The first integer to swap.
 * @b: The second integer to swap.
*/
void bubble_sort(int *array, size_t size)
{
	int i, j, temp;

	for (i = 0; i < (int)size - 1; i++)
	{
		for (j = 0; j < (int)size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
		/*print the array after each swap*/
		printf("Array after swap %d: ", i + 1);
		for (j = 0; j < (int)size; j++)
		{
			printf("%d ", array[j]);
		}
		printf("\n");
	}
}


