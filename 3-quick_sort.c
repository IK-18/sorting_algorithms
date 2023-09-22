#include "sort.h"

/**
 * partition - partitions the array using the last element as pivot
 * @array: array to be partitioned
 * @first: first element of partition
 * @last: last element of partition
 *
 * Return: index of pivot
 */
size_t partition(int *array, int first, int last, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[last];
	i = first - 1;
	for (j = first; j <= last - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[last];
	array[last] = tmp;
	print_array(array, size);
	return (i + 1);
}

/**
 * qs - sorts an array of integers using quick sort algorithm
 * @array: array to be sorted
 * @first: first element of the array
 * @last: last element of the array
 *
 * Return: Nothing
 */
void qs(int *array, int first, int last, size_t size)
{
	size_t i;

	if (first < last)
	{
		i = partition(array, first, last, size);
		qs(array, first, i - 1, size);
		qs(array, i + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: length of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}	
