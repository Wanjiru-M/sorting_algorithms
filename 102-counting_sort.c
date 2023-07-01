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
    int max = array[0];
    int i = 1;

    while (i < size) {
        if (array[i] > max)
            max = array[i];
        i++;
    }

    return max;
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max = get_max(array, size);

    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    int *sorted = malloc(size * sizeof(int));
    if (sorted == NULL) {
        free(count);
        return;
    }

    int i = 0;
    while (i <= max) {
        count[i] = 0;
        i++;
    }

    i = 0;
    while (i < (int)size) {
        count[array[i]]++;
        i++;
    }

    print_array(count, max + 1);

    i = 1;
    while (i <= max) {
        count[i] += count[i - 1];
        i++;
    }

    i = size - 1;
    while (i >= 0) {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
        i--;
    }

    i = 0;
    while (i < (int)size) {
        array[i] = sorted[i];
        i++;
    }

    free(count);
    free(sorted);
}
