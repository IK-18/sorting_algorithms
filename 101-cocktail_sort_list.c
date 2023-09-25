#include "sort.h"

/**
 * swap_nodes - swaps nodes in a doubly linked list
 * @node: node to swap
 * @prev: prev node
 * @next: next node
 *
 * Return: Nothing
 */
void swap_nodes(listint_t *node, listint_t *next)
{
	listint_t *tmp;

	tmp = next;
	if (node->prev)
		node->prev->next = tmp;
	tmp->prev = node->prev;
	if (tmp->next)
		tmp->next->prev = node;
	node->next = tmp->next;
	node->prev = tmp;
	tmp->next = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 * @array: array to be sorted
 * @size: length of array
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	bool swap = true;

	if (!list || !(*list) || !(*list)->next)
		return;
	while (swap)
	{
		swap = false;
		for(curr = *list; curr->next; curr = curr)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(curr, curr->next);
				swap = true;
				print_list(*list);
			}
			else
				curr = curr->next;
		}
		if (!swap)
			break;
		for (curr = curr->prev; curr->prev; curr = curr)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(curr->prev, curr);
				swap = true;
				if (!(curr->prev))
					*list = curr;
				print_list(*list);
			}
			else
				curr = curr->prev;
		}
	}
}
