#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	/* Calculate initial gap based on Knuth sequence */
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	/* Iterate over gaps, reducing gap in each iteration */
	for (; gap >= 1; gap /= 3)
	{
		/* Perform insertion sort for each gap */
		for (i = gap; i < size; i++)
		{
			j = i;
			/* Insertion sort within the gap */
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		/* Print the array after each gap iteration */
		print_array(array, size);
	}
}

