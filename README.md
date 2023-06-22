# Sorting Algorithms

This project implements various sorting algorithms in the C programming language. It provides functions to sort arrays of integers using different algorithms and prints the sorted arrays at each step.

## Requirements

- The code is written in C and follows the Betty style.
- Compilation is done using gcc with the options -Wall -Werror -Wextra -pedantic -std=gnu89.
- No standard library functions are used unless explicitly allowed.
- Each file should end with a new line.
- The prototypes of all functions are included in the header file `sort.h`.
- Header files are include guarded.
- There should be no more than 5 functions per file.
- The project repository should contain a README.md file.

## Files and Directories

- `0-bubble_sort.c`: Implementation of the Bubble Sort algorithm.
- `0-O`: Big O notations of the time complexity of the Bubble Sort algorithm.
- `sort.h`: Header file containing function prototypes and structure definition.
- `print_array.c`: Function to print an array of integers.
- `print_list.c`: Function to print a doubly linked list of integers.

## Compilation

To compile the sorting algorithms, run the following command:

gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-bubble_sort.c print_array.c print_list.c -o sort

## Usage

After compilation, you can run the `sort` executable to test the sorting algorithms. The program provides sample test cases that demonstrate the sorting process.

## Examples

Here is an example usage of the Bubble Sort algorithm:

```c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    print_array(array, n);

    bubble_sort(array, n);

    printf("Sorted array: ");
    print_array(array, n);

    return 0;
}
Output:
Original array: 19, 48, 99, 71, 13, 52, 96, 73, 86, 7
Sorted array: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

