#include "sort.h"

void merge_subarray(int *subarray, int *buffer, size_t start, size_t mid, size_t end);
void merge_sort_recursive(int *array, int *buffer, size_t start, size_t end);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - Merge two sorted subarrays into one sorted subarray.
 * @subarray: The array to be sorted.
 * @buffer: A temporary buffer to store the sorted subarray.
 * @start: The start index of the subarray.
 * @mid: The middle index of the subarray.
 * @end: The end index of the subarray.
 */
void merge_subarray(int *subarray, int *buffer, size_t start, size_t mid, size_t end)
{
	size_t left_size = mid - start;
	size_t right_size = end - mid;
	int *left = subarray + start;
	int *right = subarray + mid;
	size_t i = 0, j = 0, k = start;

	while (i < left_size && j < right_size)
	{
		buffer[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
	}

	while (i < left_size)
		buffer[k++] = left[i++];
	while (j < right_size)
		buffer[k++] = right[j++];

	for (k = start; k < end; k++)
		subarray[k] = buffer[k];
}

/**
 * merge_sort_recursive - Recursive function to sort an array using merge sort.
 * @array: The array to be sorted.
 * @buffer: A temporary buffer to store the sorted subarrays.
 * @start: The start index of the subarray.
 * @end: The end index of the subarray.
 */
void merge_sort_recursive(int *array, int *buffer, size_t start, size_t end)
{
	if (end - start <= 1)
		return;

	size_t mid = start + (end - start) / 2;

	merge_sort_recursive(array, buffer, start, mid);
	merge_sort_recursive(array, buffer, mid, end);

	merge_subarray(array, buffer, start, mid, end);
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
	if (array == NULL || size < 2)
		return;

	int *buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}

