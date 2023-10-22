#include "sort.h"

/**
 * _swap - Swaps two nodes of doubly linked list
 *
 * @node: node base to change
 * @list: double link list head
 *
 * Return: No Return
 */
void _swap(listint_t **node, listint_t **list)
{
	listint_t *temp = *node, *temp2, *temp3;

	if (!(*node)->prev)
		*list = (*node)->next;

	temp = temp3 = *node;
	temp2 = temp->next;

	temp->next = temp2->next;
	temp3 = temp->prev;
	temp->prev = temp2;
	temp2->next = temp;
	temp2->prev = temp3;

	if (temp2->prev)
		temp2->prev->next = temp2;


	if (temp->next)
		temp->next->prev = temp;

	*node = temp2;

}
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *
 * @list: doubly linked list
 *
 * Return: No Return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t  *head = *list, *tback, *aux;

	if (!head || (!(head->prev) && !(head->next)))
		return;

	while (head && head->next)
	{
		if (head->n > head->next->n)
		{
			aux = head;

			_swap(&aux, list);
			print_list(*list);
			head = aux;
			tback = aux;

			while (tback && tback->prev)
			{

				if (tback->n < tback->prev->n)
				{
					aux = tback->prev;

					_swap(&(aux), list);

					print_list(*list);
					tback = aux->next;
				}

				tback = tback->prev;
			}

		}
		head = head->next;
	}
}
