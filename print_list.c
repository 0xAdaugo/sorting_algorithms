#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers.
 *
 * This function prints the elements of a linked list of integers to the
 * standard output, separated by commas, followed by a newline character.
 *
 * @list: A pointer to the head of the list to be printed.
 */
void print_list(const listint_t *list)
{
	int i;  /* Loop iterator */

	i = 0;  /* Initialize the iterator to 0 */
	while (list)
	{
		if (i > 0)
			printf(", ");  /* Print a comma and space before each element (except the first) */
		printf("%d", list->n);  /* Print the current element */
		++i;  /* Move to the next element */
		list = list->next;
	}
	printf("\n");  /* Print a newline character at the end */
}

