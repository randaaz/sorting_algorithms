#include "sort.h"
#include <stdio.h>



void print_array(const int *array, size_t size);
/**
 * _new_me - Allocates memory for an array
 * @num: Number of elements
 * @size: Size of each element
 *
 * Return: A pointer to the allocated memory, or NULL if it fails
 */
void *_new_me(unsigned int num, unsigned int size)
{
	unsigned int ii = 0;
	char *pp;

	if (num == 0 || size == 0)
		return ('\0');
	pp = malloc(num * size);
	if (pp == NULL)
		return ('\0');
	for (ii = 0; ii < (num * size); ii++)
		pp[ii] = '\0';
	return (pp);
}

/**
 * m_me - Merges two subarrays
 * @ar: Array to be sorted
 * @tp: Temporary array
 * @st: Starting index of the first subarray
 * @mi: Middle index
 * @lo: Ending index of the second subarray
 */
void m_me(int *ar, int *tp, int st, int mi, int lo)
{
	int s_l = mi - st + 1, s_r = lo - mi;
	int *ar_t, *ar_r;
	int le, ri, ii = 0;

	ar_t = &tp[0];
	ar_r = &tp[s_r];
	for (le = 0; le < s_l; le++)
		ar_t[le] = ar[st + le];
	for (ri = 0; ri < s_r; ri++)
		ar_r[ri] = ar[mi + 1 + ri];
	le = 0, ri = 0, ii = st;
	while (le < s_l && ri < s_r)
	{
		if (ar_t[le] <= ar_r[ri])
			ar[ii] = ar_t[le], le++;
		else
			ar[ii] = ar_r[ri], ri++;
		ii++;
	}
	while (le < s_l)
		ar[ii] = ar_t[le], le++, ii++;
	while (ri < s_r)
		ar[ii] = ar_r[ri], ri++, ii++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(ar_t, le);
	printf("[right]: ");
	print_array(ar_r, ri);
	printf("[Done]: ");
	print_array(&ar[st], le + ri);
}
/**
 * m_t - Recursively divides the array and calls merge function
 * @ar: Array to be sorted
 * @tp: Temporary array
 * @st: Starting index
 * @lo: Ending index
 */
void m_t(int *ar, int *tp, int st, int lo)
{
	int mi;

	mi = (st + lo) / 2;
	if ((st + lo) % 2 == 0)
		mi--;
	if (mi >= st)
	{
		m_t(ar, tp, st, mi);
		m_t(ar, tp, mi + 1, lo);
		m_me(ar, tp, st, mi, lo);
	}
}
/**
 * merge_sort - Sorts an array using the merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tp;

	if (!array || size < 2)
		return;
	tp = _new_me(size, sizeof(int));
	m_t(array, tp, 0, size - 1);
	free(tp);
}
