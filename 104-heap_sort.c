#include "sort.h"

/* Function prototypes */
void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Adjust the binary tree rooted at 'root' to be a max heap.
 * @array: An array representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The size of the base row of the tree.
 * @root: The index of the current root node.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, largest;

	left = 2 * root + 1;
	right = 2 * root + 2;
	largest = root;

	/* Find the largest element among root, left child, and right child */
	if (left < base && array[left] > array[largest])
		largest = left;
	if (right < base && array[right] > array[largest])
		largest = right;

	/* If the largest element is not the current root, swap and continue */
	if (largest != root)
	{
		swap_ints(array + root, array + largest);
		print_array(array, size);
		max_heapify(array, size, base, largest);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order using heap sort.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort algorithm
 * and prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* Build the initial max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	/* Extract elements one by one from the heap */
	for (i = size - 1; i > 0; i--)
	{
		/* Swap the root (max element) with the last element */
		swap_ints(array, array + i);
		print_array(array, size);

		/* Call max_heapify to adjust the heap after swapping */
		max_heapify(array, size, i, 0);
	}
}

