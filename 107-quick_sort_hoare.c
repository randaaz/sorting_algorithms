#include "sort.h"
/**
 * sw - Swaps two elements in an array.
 * @ar: The array containing elements to be swapped.
 * @t1: Index of the first element.
 * @t2: Index of the second element.
 */
void sw(int *ar, ssize_t t1, ssize_t t2)
{
	int tp;

	tp = ar[t1];
	ar[t1] = ar[t2];
	ar[t2] = tp;
}
/**
 * h_p - Finds the partition position using the Hoare partition scheme.
 * @ar: The array to be partitioned.
 * @fs: The starting index of the sub-array.
 * @lt: The ending index of the sub-array.
 * @size: The size of the array.
 *
 * Return: The partition position.
 */
int h_p(int *ar, int fs, int lt, int size)
{
	int cu = fs - 1, fd = lt + 1;
	int pi = ar[lt];

	while (1)
	{

		do {
			cu++;
		} while (ar[cu] < pi);
		do {
			fd--;
		} while (ar[fd] > pi);
		if (cu >= fd)
			return (cu);
		sw(ar, cu, fd);
		print_array(ar, size);
	}
}
/**
 * rs - Recursive function to perform quicksort using Hoare partition.
 * @ar: The array to be sorted.
 * @fs: The starting index of the sub-array.
 * @lt: The ending index of the sub-array.
 * @size: The size of the array.
 */
void rs(int *ar, ssize_t fs, ssize_t lt, int size)
{
	ssize_t pos = 0;

	if (fs < lt)
	{
		pos = h_p(ar, fs, lt, size);
		rs(ar, fs, pos - 1, size);
		rs(ar, pos, lt, size);
	}
}
/**
 * quick_sort_hoare - Sorts an array of integers using the Quick Sort
 * algorithm with Hoare partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	rs(array, 0, size - 1, size);
}
