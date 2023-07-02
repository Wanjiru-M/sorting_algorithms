#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, size_t size) {
    // Find the largest number in the array
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Create a counting array of size max+1 and initialize all elements to 0
    int *count = (int *)malloc((max + 1) * sizeof(int));
    if (count == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each number in the array
    for (size_t i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Print the counting array
    for (int i = 0; i <= max; i++) {
        printf("%d, ", count[i]);
    }
    printf("\n");

    // Update the original array with the sorted values
    size_t index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            array[index++] = i;
            count[i]--;
        }
    }

    free(count);
}

// Helper function to print the array
void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

// Main function for testing
int main(void) {
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    counting_sort(array, n);
    printf("\n");
    print_array(array, n);

    return 0;
}

