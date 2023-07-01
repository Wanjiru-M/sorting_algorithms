#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_ints(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
    size_t interval, i, j;

    if (array == NULL || size < 2)
        return;

    // Calculate initial interval
    interval = 1;
    while (interval < (size / 3))
        interval = interval * 3 + 1;

    // Perform shell sort
    do
    {
        for (i = interval; i < size; i++)
        {
            j = i;
            while (j >= interval && array[j - interval] > array[j])
            {
                swap_ints(&array[j], &array[j - interval]);
                j -= interval;
            }
        }
        print_array(array, size);
        interval /= 3;
    } while (interval >= 1);
}

