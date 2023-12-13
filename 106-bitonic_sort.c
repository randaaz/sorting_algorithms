#include "sort.h"

/**
 * _sp_me - Swap two elements in the array based on the specified order.
 *
 * @array: The array of integers to be modified.
 * @it1: Index of the first element.
 * @it2: Index of the second element.
 * @ord: Order of the swap (1 for ascending, 0 for descending).
 */

void _sp_me(int array[], int it1, int it2, int ord)
{
	int t;

	if (ord == (array[it1] > array[it2]))
	{
		t = array[it1];
		array[it1] = array[it2];
		array[it2] = t;
	}
}

/**
 * _mg - Merge two subarrays in the array.
 *
 * @array: The array of integers to be modified.
 * @l: Starting index of the subarray.
 * @nt: Number of elements in the subarray.
 * @ord: Order of merging (1 for ascending, 0 for descending).
 */

void _mg(int array[], int l, int nt, int ord)
{
	int m, j;

	if (nt > 1)
	{
		m = nt / 2;
		for (j = l; j < l + m; j++)
			_sp_me(array, j, j + m, ord);
		_mg(array, l, m, ord);
		_mg(array, l + m, m, ord);
	}
}

/**
 * b_sort - Recursive function to perform bitonic sort on the array.
 *
 * @array: The array of integers to be sorted.
 * @l: Starting index of the subarray.
 * @nt: Number of elements in the subarray.
 * @ord: Order of sorting (1 for ascending, 0 for descending).
 * @size: Total size of the array.
 */

void b_sort(int array[], int l, int nt, int ord, int size)
{
	int m;

	if (nt > 1)
	{
		if (ord >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nt, size);
			print_array(&array[l], nt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nt, size);
			print_array(&array[l], nt);
		}
		m = nt / 2;
		b_sort(array, l, m, 1, size);
		b_sort(array, l + m, m, 0, size);
		_mg(array, l, nt, ord);
		if (ord <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nt, size);
			print_array(&array[l], nt);
		}
		if (ord >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nt, size);
			print_array(&array[l], nt);
		}
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */

void bitonic_sort(int *array, size_t size)
{
	int ord = 1;

	if (!array || size < 2)
		return;
	b_sort(array, 0, size, ord, size);
}
