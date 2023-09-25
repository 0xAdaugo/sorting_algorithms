#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	/* Temporary variable to hold the value during the swap */
	int temp;

	/* Swap the integers */
	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using bubble sort.
 * @array: Pointer to the array of integers to sort.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	/* Check if the array is NULL or the size is less than 2 */
	if (array == NULL || size < 2)
		return;

	/* Perform bubble sort */
	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			/* If the current element is greater than the next element, swap */
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size); /* Print the array after the swap */
				bubbly = false; /* Set bubbly to false to continue sorting */
			}
		}
		len--;
	}
}

