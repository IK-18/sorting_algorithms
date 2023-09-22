#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list to sort
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *key;
	int holder;

	if (!list)
		return;
	for (key = (*list)->next; key; key = key->next)
	{
		holder = key->n;
		tmp = key->prev;
		while (tmp && tmp->n > holder)
		{
			*(int *)&tmp->next->n = tmp->n;
			*(int *)&tmp->n = holder;
			tmp = tmp->prev;
			if (!tmp)
				break;
			print_list(*list);
		}
	}
	print_list(*list);
}
