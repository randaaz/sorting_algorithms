#include "sort.h"

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
 * lomuto_partition - Implements the Lomuto partition scheme for Quick Sort
 * @array: Pointer to the array to be partitioned
 * @fz: Size of the array
 * @ls: Starting index of the sub-array to be partitioned
 * @ho: Ending index of the sub-array to be partitioned
 *
 * Return: The partition index
 */
size_t lomuto_partition(int *array, size_t fz, ssize_t ls, ssize_t ho)
{
	int ii, jj, pivot = array[ho];

	for (ii = jj = ls; jj < ho; jj++)
		if (array[jj] < pivot)
			s_n(array, fz, &array[jj], &array[ii++]);
	s_n(array, fz, &array[ii], &array[ho]);

	return (ii);
}
/**
 * qu_so_me - Function to recursively sort an array using Quick Sort algorithm
 * @array: Pointer to the array to be sorted
 * @fz: Size of the array
 * @ls: Starting index of the sub-array to be sorted
 * @ho: Ending index of the sub-array to be sorted
 */
void qu_so_me(int *array, size_t fz, ssize_t ls, ssize_t ho)
{
	if (ls < ho)
	{
		size_t pos = lomuto_partition(array, fz, ls, ho);

		qu_so_me(array, fz, ls, pos - 1);
		qu_so_me(array, fz, pos + 1, ho);
	}
}
/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	qu_so_me(array, size, 0, size - 1);
}
