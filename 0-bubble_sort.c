#include "sort.h"

/**
 * bubble_sort - a function that uses bubble sort on an array of ints
 * @array: the array
 * @size: size of the array
 * Return: Void
 **/

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tmp;
	int flag;

	i = 0;

	if (array == NULL)
	{
		return;
	}
	if (size == 1)
	{
		print_array(array, size);
		return;
	}
	while (flag != INT_MAX)
	{
		tmp = INT_MAX;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
			i = i + 1;
			flag = tmp;
		}
		i = 0;
	}
}
