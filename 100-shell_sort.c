#include "sort.h"

/**
 * shel_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: length of array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j, tmp;

	while (gap < ((int)size) / 3)
		gap = (3 * gap) + 1;
	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];
			j = i;
			while (j > gap - 1 && array[j - gap] >= tmp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = tmp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
