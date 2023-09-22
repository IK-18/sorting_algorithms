#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	bool swapped;

	if (!array)
		return;
	for (i = 0; i < size; i++)
	{
		swapped = false;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}
