#include "sort.h"

/* Function prototypes */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Merge two subarrays of integers.
 * @subarr: The subarray containing the elements to merge.
 * @buff: A buffer to store the sorted subarray.
 * @front: The index of the start of the subarray.
 * @mid: The index marking the boundary between subarrays.
 * @back: The index of the end of the subarray.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
	size_t i, j, k = 0;

	/* Print the left and right subarrays being merged */
	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);
	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	/* Merge the two subarrays into the buffer */
	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];

	/* Copy the sorted result from the buffer back to the original array */
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	/* Print the merged subarray */
	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	/* Check if there is more than one element in the subarray */
	if (back - front > 1)
	{
		/* Calculate the middle index */
		mid = front + (back - front) / 2;

		/* Recursively sort the left and right subarrays */
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);

		/* Merge the sorted subarrays */
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *              using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	/* Check for invalid input or if sorting is unnecessary */
	if (array == NULL || size < 2)
		return;

	/* Allocate memory for a buffer to store the sorted result */
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	/* Call the recursive merge sort function */
	merge_sort_recursive(array, buff, 0, size);

	/* Free dynamically allocated memory */
	free(buff);
}

