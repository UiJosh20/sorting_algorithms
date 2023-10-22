#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next;
	listint_t *prev = curr->prev;
	listint_t *next = curr->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (curr)
	{
		while (prev && prev->n > curr->n)
		{
			if (prev->prev)
				prev->prev->next = curr;
			else
				*list = curr;
			curr->prev = prev->prev;
			prev->next = next;
			if (next)
				next->prev = prev;
			curr->next = prev;
			prev->prev = curr;
			print_list(*list);
		}
		curr = next;
	}
}
