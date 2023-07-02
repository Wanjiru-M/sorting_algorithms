#include "sort.h"

/**
 * merge - Merge two subarrays into one sorted array.
 * @array: The array to be sorted.
 * @left: Pointer to the left subarray.
 * @left_size: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @right_size: Size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    size_t i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    while (i < left_size)
        array[k++] = left[i++];

    while (j < right_size)
        array[k++] = right[j++];

    printf("[Done]: ");
    print_array(array, left_size + right_size);
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *              using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the intermediate steps during the merge process.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t mid = size / 2;
    size_t left_size = mid;
    size_t right_size = size - mid;

    int *left = array;
    int *right = array + mid;

    printf("Splitting...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    merge_sort(left, left_size);
    merge_sort(right, right_size);

    merge(array, left, left_size, right, right_size);

    printf("[Done]: ");
    print_array(array, size);
}

