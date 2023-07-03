#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, size_t size) {
    if (size <= 1)
        return;

    /* Find the maximum value in the array */
    int max = array[0];
    size_t i;
    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a counting array of size max + 1 */
    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    /* Initialize the counting array with zeros */
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    /* Count the occurrences of each number in the input array */
    for (i = 0; i < size; i++) {
        count[array[i]]++;
    }

    /* Print the counting array */
    for (i = 0; i <= max; i++) {
        printf("%d, ", count[i]);
    }
    printf("\n");

    /* Modify the counting array to store the cumulative counts */
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    /* Create a temporary output array */
    int *output = malloc(size * sizeof(int));
    if (output == NULL) {
        printf("Memory allocation failed!\n");
        free(count);
        return;
    }

    /* Build the sorted array */
    for (ssize_t j = size - 1; j >= 0; j--) {
        output[count[array[j]] - 1] = array[j];
        count[array[j]]--;
    }

    /* Copy the sorted array back to the input array */
    for (i = 0; i < size; i++) {
        array[i] = output[i];
    }

    /* Free dynamically allocated memory */
    free(count);
    free(output);
}

