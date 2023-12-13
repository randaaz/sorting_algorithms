#include "sort.h"

/**
 * cal_me - Merges two halves of an array in ascending order
 * @array: The array to be sorted
 * @st: Starting index of the first half
 * @to: Ending index of the second half
 * @wo: Temporary array for merging
 */
void cal_me(int *array, size_t st, size_t to, int *wo)
{
	size_t ii = st, jj, kk, mi;

	jj = mi = (st + to) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + st, mi - st);
	printf("[right]: ");
	print_array(array + mi, to - mi);
	for (kk = st; kk < to; kk++)
		if (ii < mi && (jj >= to || array[ii] <= array[jj]))
		{
			wo[kk] = array[ii++];
		}
		else
		{
			wo[kk] = array[jj++];
		}
}
/**
 * m_so_do - Helper function for merge_sort
 * @arr: The array to be sorted
 * @st: Starting index of the sub-array
 * @to: Ending index of the sub-array
 * @wo: Temporary array for merging
 */
void m_so_do(int *arr, size_t st, size_t to, int *wo)
{
	size_t mi;

	mi = (st + to) / 2;
	if (to - st < 2)
	{
		return;
	}
	m_so_do(wo, st, mi, arr);
	m_so_do(wo, mi, to, arr);
	cal_me(arr, st, to, wo);
}

/**
 * merge_sort - Sorts an array of integers
 * merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *tp;
	size_t ii;

	if (!array || size < 2)
		return;
	tp = malloc(sizeof(int) * size);
	if (!tp)
		return;
	for (ii = 0; ii < size; ii++)
		tp[ii] = array[ii];
	m_so_do(tp, 0, size, array);
	free(tp);
}
