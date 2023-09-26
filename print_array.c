#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers.
 *
 * This function prints the elements of an integer array to the standard output,
 * separated by commas, followed by a newline character.
 *
 * @array: A pointer to the array to be printed.
 * @size: The number of elements in the array.
 */
void print_array(const int *array, size_t size)
{
	size_t i;  /* Loop iterator */

	i = 0;  /* Initialize the iterator to 0 */
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");  /* Print a comma and space before each element (except the first) */
		printf("%d", array[i]);  /* Print the current element */
		++i;  /* Move to the next element */
	}
	printf("\n");  /* Print a newline character at the end */
}

