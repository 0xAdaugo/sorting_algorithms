#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: A poiter to the second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	/* Update the next pointer of the first node*/
	(*n1)->next = n2->next;

	/*Check if the second node has a next node and update its previous pointer*/
	if (n2->next != NULL)
		n2->next->prev = *n1;

	/*Update the previous pointer of the second node*/
	n2->prev = (*n1)->prev;


	/*Update the next pointer of the second node to the first node*/
	n2->next = *n1;

	/*Check if the first node has a previous node and update its next pointer*/
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		/*If the first node is the head, update the head pointer*/
		*h = n2;

	/*Update the previous pointer of the first node to the second node*/
	(*n1)->prev = n2;

	/*Update the first node pointer to the new position*/
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	/*Check for NULL or single-node list*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/*Iterate through the list*/
	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;

		/*Compare and swap nodes until the correct position is found*/
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);

			/*Print the list after each swap*/
			print_list((const listint_t *)*list);
		}
	}
}

