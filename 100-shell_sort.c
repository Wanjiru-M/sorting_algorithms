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
 *              order using the Shell sort algorithm
 *              with the Knuth sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
    size_t interval = 1;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    // Calculate initial interval using Knuth sequence
    while (interval < size / 3)
        interval = interval * 3 + 1;

    while (interval > 0) {
        for (i = interval; i < size; i++) {
            j = i;
            while (j >= interval && array[j - interval] > array[j]) {
                swap_ints(&array[j], &array[j - interval]);
                j -= interval;
            }
        }
        print_array(array, size);
        interval = (interval - 1) / 3; // Decrease interval
    }
}

