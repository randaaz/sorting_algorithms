#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	int t;
	size_t j, c;

	if (!array || !size)
		return;

	j = 0;
	while (j < size)
	{
		for (c = 0; c < size - 1; c++)
		{
			if (array[c] > array[c + 1])
			{
				t = array[c];
				array[c] = array[c + 1];
				array[c + 1] = t;
				print_array(array, size);
			}
		}
		j++;
	}
}
