#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t ii, jj, c;
	int t;

	if (!array || !size)
		return;
	for (ii = 0; ii < size - 1; ii++)
	{
		for (jj = size - 1, c = ii + 1; jj > ii; jj--)
		{
			if (array[jj] < array[c])
			{
				c = jj;
			}
		}
		if (array[ii] > array[c])
		{
			t = array[ii];
			array[ii] = array[c];
			array[c] = t;
			print_array(array, size);
		}
	}
}
