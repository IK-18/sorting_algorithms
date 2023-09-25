#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: length of the array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *count, *out, max;
	size_t i;

	if (size < 2 || !array)
		return;
	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	out = malloc(sizeof(int) * size);
	for (i = 0; (int)i <= max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (i = 1; (int)i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < size; i++)
	{
		out[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = out[i];
	free(out);
	free(count);
}
