#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	/* Store the value of the first integer in a temporary variable */
	int tmp = *a;

	/* Assign the value of the second integer to the first integer */
	*a = *b;

	/*Assign the temporary variable to the second integer*/
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	/* Initialize a pointer to store the minimum value */
	int *min;
	size_t i, j;

	/* Check for invalid input or arrays with 1 or fewer elements */
	if (array == NULL || size < 2)
		return;

	/* Iterate through the array */
	for (i = 0; i < size - 1; i++)
	{
		/* Assume the current element is the minimum */
		min = array + i;

		/* Find the minimum element in the unsorted portion of the array */
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		/* If the minimum element is not the current element, swap them */
		if ((array + i) != min)
		{
			swap_ints(array + i, min);

			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}

