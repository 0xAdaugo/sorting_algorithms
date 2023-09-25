#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Perform partitioning on a
 * subset of an integer array using Lomuto scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset.
 * @right: The ending index of the subset.
 *
 * Returns: The final pivot index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Recursively apply quicksort
 * algorithm using Lomuto partitioning.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array subset.
 * @right: The ending index of the array subset.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order using quicksort.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Utilizes the Lomuto partition scheme
 * and prints the array after each swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

