#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
    int max_val = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max_val)
            max_val = array[i];
    }
    return max_val;
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max_val = get_max(array, size);

    int *count = malloc(sizeof(int) * (max_val + 1));
    if (count == NULL)
        return;

    int *sorted = malloc(sizeof(int) * size);
    if (sorted == NULL)
    {
        free(count);
        return;
    }

    for (int i = 0; i <= max_val; i++)
        count[i] = 0;

    for (size_t i = 0; i < size; i++)
        count[array[i]]++;

    print_array(count, max_val + 1);

    for (int i = 1; i <= max_val; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (size_t i = 0; i < size; i++)
        array[i] = sorted[i];

    free(sorted);
    free(count);
}

