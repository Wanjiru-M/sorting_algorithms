#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence
 *
 * @array: The array to sort
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i, j;
	int temp;

	/* Calculate the initial interval using Knuth sequence */
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
				array[j] = array[j - interval];

			array[j] = temp;
		}

		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}

