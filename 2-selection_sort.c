#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: length of array
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp, swap;

	for (i = 0; i < size; i++)
	{
		tmp = array[i];
		swap = 0;
		for (j = i; j < size; j++)
		{
			if (array[j] < tmp)
			{
				tmp = array[j];
				min = j;
				swap = 1;
			}
		}
		if (!swap)
			continue;
		array[min] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
}
