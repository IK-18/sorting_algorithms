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
	size_t i, j, min, tmp, swap = 0;

	for (i = 0; i < size; i++)
	{
		for (min = i, j = i; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				swap = 1;
			}
		}
		if (swap)
		{
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
			print_array(array, size);
			swap = 0;
		}
	}
}
