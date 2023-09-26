#include "sort.h"

/* Function prototypes */
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	/* Find the maximum element in the array */
	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	/* Count the occurrences of each digit at the current significant position */
	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	/* Calculate cumulative counts */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the sorted array in the buffer */
	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	/* Copy the sorted result from the buffer back to the original array */
	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending order
 *              using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm and prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	/* Check for invalid input or if sorting is unnecessary */
	if (array == NULL || size < 2)
		return;

	/* Allocate memory for a buffer to store the sorted result */
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	/* Find the maximum element in the array */
	max = get_max(array, size);

	/* Sort the array based on significant digits from LSD to MSD */
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	/* Free dynamically allocated memory */
	free(buff);
}

