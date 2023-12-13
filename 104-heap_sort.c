#include "sort.h"
#define par(x) (((x) - 1) / 2)
#define left_ch(x) (((x) * 2) + 1)

/**
 * s_n - Function to swap two integers in an array and print the array
 * @arr: Pointer to the array of integers
 * @sz1: Size of the array
 * @r: Pointer to the first integer to be swapped
 * @d: Pointer to the second integer to be swapped
 */
void s_n(int *arr, size_t sz1, int *r, int *d)
{
	if (*r != *d)
	{
		*r = *r + *d;
		*d = *r - *d;
		*r = *r - *d;
		print_array((const int *)arr, sz1);
	}

}

/**
 * _sif - Perform the heapify operation on a subtree rooted at index 'st'.
 *
 * @array: The array of integers to be modified.
 * @st: The index of the subtree to be heapified.
 * @ed: The end index of the heap.
 * @size: The size of the array.
 */

void _sif(int *array, size_t st, size_t ed, size_t size)
{
	size_t r = st, _sp_me, ch;

	while (left_ch(r) <= ed)
	{
		ch = left_ch(r);
		_sp_me = r;
		if (array[_sp_me] < array[ch])
			_sp_me = ch;
		if (ch + 1 <= ed && array[_sp_me] < array[ch + 1])
			_sp_me = ch + 1;
		if (_sp_me == r)
			return;
		s_n(array, size, &array[r], &array[_sp_me]);
		r = _sp_me;
	}

}

/**
 * _heap - Build a max heap from the array.
 *
 * @array: The array of integers to be modified.
 * @size: The size of the array.
 */

void _heap(int *array, size_t size)
{
	ssize_t st;

	st = par(size - 1);
	while (st >= 0)
	{
		_sif(array, st, size - 1, size);
		st--;
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
	size_t ed;

	if (!array || size < 2)
		return;
	_heap(array, size);
	ed = size - 1;
	while (ed > 0)
	{
		s_n(array, size, &array[ed], &array[0]);
		ed--;
		_sif(array, 0, ed, size);
	}
}
