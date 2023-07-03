#include "sort.h"

/**
 * sift_down - Perform sift-down operation on a binary tree.
 * @array: The array representing the binary tree.
 * @size: The size of the array.
 * @root: The root index of the subtree to sift-down.
 * @end: The last index of the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max, child;
	int swap;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		max = root;

		if (array[child] > array[max])
			max = child;
		if (child + 1 <= end && array[child + 1] > array[max])
			max = child + 1;

		if (max == root)
			return;

		swap = array[root];
		array[root] = array[max];
		array[max] = swap;
		print_array(array, size);

		root = max;
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order
 *             using the Heap sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		swap = array[0];
		array[0] = array[i];
		array[i] = swap;
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}

