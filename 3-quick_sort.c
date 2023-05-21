#include "sort.h"

void swap(int *i, int *j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low;
    int j = low;

    while (j < high) {
        if (array[j] < pivot) {
            swap(&array[i], &array[j]);
	    if (i != j)
	    {
		    print_array(array, size);
	    }
            i = i + 1;
        }
        j = j + 1;
    }
    swap(&array[i], &array[high]);
    if (i != j)
    {
	    print_array(array, size);
    }
    return i;
}

void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int i;

	if (low >= high)
	{
		return;
	}
	i = partition(array, low, high, size);
        quicksort_recursive(array, low, i - 1, size);
	quicksort_recursive(array, i + 1, high, size);
}

/**
 * quick_sort -Sort an array using quick_sort algorithm
 * @array: array
 * @size: size
 **/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	quicksort_recursive(array, 0, size - 1, size);
}
