#include "sort.h"
#include <stdio.h>
/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting Sort algorithm
 * @array: pointer to the array of integers
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, i;
	int *count, *output;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	
	for (i = 0; i <= max; i++)
		printf("%d%s", count[i], i == max ? "\n" : ", ");

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
