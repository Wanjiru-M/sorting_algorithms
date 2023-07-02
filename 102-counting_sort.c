#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    // Find the maximum element in the array
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Create the counting array of size max + 1
    int *counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    // Initialize the counting array with 0s
    for (int i = 0; i <= max; i++) {
        counting_array[i] = 0;
    }

    // Count the occurrences of each element in the array
    for (size_t i = 0; i < size; i++) {
        counting_array[array[i]]++;
    }

    // Print the counting array
    for (int i = 0; i <= max; i++) {
        printf("%d", counting_array[i]);
        if (i != max) {
            printf(", ");
        }
    }
    printf("\n");

    // Sort the array using the counting array
    size_t index = 0;
    for (int i = 0; i <= max; i++) {
        while (counting_array[i] > 0) {
            array[index] = i;
            counting_array[i]--;
            index++;
        }
    }

    free(counting_array);
}

