#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int pass, current;
	int temp;

	if (size < 2)
	return;

	for (pass = 0; pass < size; pass++)
	{
	current = 0;
	do {
		if (array[current] > array[current + 1])
		{
		temp = array[current];
		array[current] = array[current + 1];
		array[current + 1] = temp;
		print_array(array, size);
		}
		current++;
		} while (current < size - pass - 1);
	}
}

