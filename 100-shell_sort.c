#include "sort.h"

/**
 * _max - Computes the initial value of the gap sequence for Shell sort
 * @size: The size of the array to be sorted
 * Return: The maximum value for the gap sequence.
 *
 */

size_t _max(size_t size)
{
	size_t num;

	num = 1;
	while (num < size)
		num = num * 3 + 1;
	return ((num - 1) / 3);
}

/**
 * shell_sort -  sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t g, ii, jj;
	int t;

	if (!array || !size)
		return;

	for (g = _max(size); g; g = (g - 1) / 3)
	{
		for (ii = g; ii < size; ii++)
		{
			t = array[ii];
			for (jj = ii; jj > g - 1 && array[jj - g] > t; jj -= g)
			{
				array[jj] = array[jj - g];
			}
			array[jj] = t;
		}
		print_array(array, size);
	}
}
