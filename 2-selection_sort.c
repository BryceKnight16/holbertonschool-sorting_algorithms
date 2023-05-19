#include "sort.h"

/**
 * swap - Swaps two ints.
 * @a: Pointer to the first int.
 * @b: Pointer to the second int.
 *Return: Void
 **/

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
* selection_sort - Sorts an array of ints using Selection Sort
 * @array: Pointer to the first element of the array.
 * @size: Size of the array.
 * Return: Void
 **/

void selection_sort(int *array, size_t size)
{
	size_t current_index;

	current_index = 0;
	if (array == NULL)
	{
		return;
	}
	while (current_index < (size - 1))
	{
		size_t min_index = current_index;
		size_t unsorted_index = current_index;

		while (unsorted_index < size)
		{
			if (array[unsorted_index] < array[min_index])
			{
				min_index = unsorted_index;
			}
			unsorted_index = unsorted_index + 1;
		}
		swap(&array[current_index], &array[min_index]);
		print_array(array, size);
		current_index = current_index + 1;
	}
}
