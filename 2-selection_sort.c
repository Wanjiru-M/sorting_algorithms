#include "sort.h"

/**
 * selection_sort - sorts an array following the selection sort algorithm
 * @array: array to sort
 * @size: size of the array;
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_idx;
	int tmp;

	if (size < 2)
		return;

	i = 0;

loop:
	min_idx = i;
	j = i + 1;

	do {
		if (array[j] < array[min_idx])
			min_idx = j;
		j++;
	} while (j < size);

	if (min_idx != i)
	{
		tmp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = tmp;
		print_array(array, size);
	}

	i++;

	if (i < size - 1)
		goto loop;
}
