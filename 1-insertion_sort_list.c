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
	listint_t *tmp;
	int holder;

	if (!list)
		return;
	tmp = *list;
	while (tmp)
	{
		while (tmp)
		{
			if (tmp->next)
			{
				if (tmp->n > tmp->next->n)
				{
					holder = tmp->n;
					*(int *)&tmp->n = tmp->next->n;
					*(int *)&tmp->next->n = holder;
					tmp = *list;
					print_list(*list);
					break;
				}
			}
			tmp = tmp->next;
		}
	}
}
