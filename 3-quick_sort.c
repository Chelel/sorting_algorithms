#include "sort.h"
/**
 * sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * swap - swaps two values in an array
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - sorts a partition of data in relation to a pivot
 *
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 *
 * Return: New Pivot
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	{
		return(i + 1;)
	}
}
/**
 * quicksort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 *
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 *
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
	{
		return;
	}
	int pivot = partition(array, 0, size - 1);
	/*print the array after each swap*/
	printf("Array after swap: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	quick_sort(array, pivot);
	quick_sort(array + pivot + 1, size - pivot - 1);
}
