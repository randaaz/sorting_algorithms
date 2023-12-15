#include "sort.h"
#include <stdio.h>

/**
 * g_M - Finds the maximum element in an integer array.
 * @ar: The array to search.
 * @num: Number of elements in the array.
 *
 * Return: The maximum element in the array.
 */
int g_M(int *ar, int num)
{
	int ii, mm = ar[0];

	for (ii = 1; ii < num; ii++)
		if (ar[ii] > mm)
			mm = ar[ii];
	return (mm);
}

/**
 * co_So - Sorts an array of integers using the Counting Sort algorithm
 * @ar: The array to be sorted
 * @num: Number of elements in the array
 * @exp: The current digit place value (1, 10, 100, ...).
 * @op: The output array to store sorted elements.
 */
void co_So(int *ar, size_t num, int exp, int *op)
{
	int ii;
	int co[10] = {0};

	for (ii = 0; ii < (int)num; ii++)
		co[(ar[ii] / exp) % 10]++;

	for (ii = 1; ii < 10; ii++)
		co[ii] += co[ii - 1];

	for (ii = num - 1; ii >= 0; ii--)
	{
		op[co[(ar[ii] / exp) % 10] - 1] = ar[ii];
		co[(ar[ii] / exp) % 10]--;
	}

	for (ii = 0; ii < (int)num; ii++)
		ar[ii] = op[ii];
}

/**
 * radix_sort - Sorts an array
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int exp, mi = 0;
	int *op = '\0';

	if (array == NULL || size < 2)
		return;

	mi = g_M(array, size);
	op = malloc(size * sizeof(int));
	if (op == NULL)
		return;
	for (exp = 1; mi / exp > 0; exp *= 10)
	{
		co_So(array, size, exp, op);
		print_array(array, size);
	}
	free(op);
}
