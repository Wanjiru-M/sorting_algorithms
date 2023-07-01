#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
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
    for (; interval >= 1; interval /= 3)
    {
        for (i = interval; i < size; i++)
        {
            j = i;
            while (j >= interval && array[j - interval] > array[j])
            {
                swap_ints(&array[j], &array[j - interval]);
                j -= interval;
                goto check_interval;
            }
        }
    check_interval:
        print_array(array, size);
    }
}

