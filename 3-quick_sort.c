#include "sort.h"

/**
 * swap_numbers - swaps the position of two numbers in an array
 * @array: the array
 * @num1: first number
 * @num2: second number
 * @size: size of the array
 **/
void swap_numbers(int *array, int *num1, int *num2, size_t size)
{
	int temp = *num1;

	*num1 = *num2;
	*num2 = temp;
	print_array(array, size);
}

/**
 * partition - partition function for the array
 * @array: the array
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: number of changes made
 **/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int index = low;
	int i = 0;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (index != i)
				swap_numbers(array, &array[i], &array[index], size);
			index++;
		}
	}
	if (index != high)
		swap_numbers(array, &array[high], &array[index], size);
	return (index);
}

/**
 * quickSort - recursive function to perform quicksort
 * @array: the array
 * @low: low index
 * @high: high index
 * @size: size of the array
 **/
void quickSort(int *array, int low, int high, size_t size)
{
	int changes = 0;

	if (low < high)
	{
		changes = partition(array, low, high, size);
		quickSort(array, low, changes - 1, size);
		quickSort(array, changes + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using quicksort
 * @array: the array
 * @size: size of the array
 **/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}

