#include "sort.h"

void print_array(const int *array, size_t size);

/**
 * sift_down - Perform the sift-down operation on a heap.
 * @array: The array representing the heap.
 * @size: The size of the heap.
 * @root: The root index of the heap.
 * @end: The end index of the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < end && array[left] > array[max])
		max = left;

	if (right < end && array[right] > array[max])
		max = right;

	if (max != root)
	{
		int temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		print_array(array, size);
		sift_down(array, size, max, end);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order using the
 *             Heap sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	size_t i;

	for (i = size / 2 - 1; i > 0; i--)
		sift_down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, 0, i);
	}

	print_array(array, size);
}

