#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * recursive_quick_sort - Recursively sorts an array using Quick sort
 * @array: The array to be sorted
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: Number of elements in the array
 */
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		recursive_quick_sort(array, low, pivot - 1, size);
		recursive_quick_sort(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Implements Lomuto partition scheme for Quick sort
 * @array: The array to be partitioned
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: Number of elements in the array
 *
 * Return: The index where the pivot should be
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
