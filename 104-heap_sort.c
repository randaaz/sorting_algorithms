#include "sort.h"
#include <stdio.h>

/**
 * _so - Swap two integers.
 * @c: Pointer to the first integer.
 * @d: Pointer to the second integer.
 */

void _so(int *c, int *d)
{
	int r = *c;

	*c = *d;
	*d = r;
}

/**
 * _max_me - Heapify subtree rooted at given index.
 * @array: Array of integers.
 * @size: Size of the array.
 * @ind: Index of the root of the subtree.
 * @n: Size of the heap.
 */

void _max_me(int *array, size_t size, int ind, size_t n)
{
	int lar = ind;
	int lf = 2 * ind + 1;
	int rt = 2 * ind + 2;

	if (lf < (int)n && array[lf] > array[lar])
		lar = lf;

	if (rt < (int)n && array[rt] > array[lar])
		lar = rt;

	if (lar != ind)
	{
		_so(&array[ind], &array[lar]);
		print_array(array, size);
		_max_me(array, size, lar, n);
	}
}

/**
 * heap_sort - Sorts an array of integers in
 * ascending order using the Heap sort algorithm
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */

void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = (size - 2) / 2; j >= 0; --j)
		_max_me(array, size, j, size);

	for (j = (size - 1); j > 0; --j)
	{
		_so(&array[0], &array[j]);
		print_array(array, size);

		_max_me(array, size, 0, j);
	}
}
