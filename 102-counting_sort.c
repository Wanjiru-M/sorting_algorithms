#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, size_t size) {
    if (size <= 1)
        return;

    size_t i;
    int max = array[0];

    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    int *output = malloc(size * sizeof(int));
    if (output == NULL) {
        printf("Memory allocation failed!\n");
        free(count);
        return;
    }

    for (ssize_t j = size - 1; j >= 0; j--) {
        output[count[array[j]] - 1] = array[j];
        count[array[j]]--;
    }

    for (i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(count);
    free(output);
}

