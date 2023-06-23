#include "sort.h"
#include <stdio.h>
/**
 * void selection_sort:function that sorts
 * an array of integers in ascending order
 * using the Selection sort algorithm.
 * prints the array after each time
 * two elements are swapped
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min_idx, temp;

	for (i = 0; i < (int)size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
		}
		/*print the array after each swap*/
		printf("%d", i + 1);
		for (j = 0; j < (int)size; j++)
		{
			printf("%d ", array[j]);
		}
		printf("\n");
	}
}
