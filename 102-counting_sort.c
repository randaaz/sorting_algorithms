#include "sort.h"
#include <stdio.h>

/**
 * _call - Allocates memory for an array and initializes it with zeros.
 * @nm: Number of elements in the array.
 * @size: Size of each element in the array.
 *
 * Return: A pointer to the allocated memory, or NULL if allocation fails.
 */

void *_call(unsigned int nm, unsigned int size)
{
	unsigned int j = 0;
	char *po;

	if (nm == 0 || size == 0)
		return ('\0');
	po = malloc(nm * size);
	if (po == NULL)
		return ('\0');
	for (j = 0; j < (nm * size); j++)
		po[j] = '\0';
	return (po);
}

/**
 * counting_sort - function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void counting_sort(int *array, size_t size)
{
	int inx, maxi = 0, *coun = '\0', *t = '\0';
	size_t j;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size; j++)
		if (array[j] > maxi)
			maxi = array[j];
	coun = _call(maxi + 1, sizeof(int));
	t = _call(size + 1, sizeof(int));

	for (j = 0; j < size; j++)
		coun[array[j]]++;

	for (inx = 1; inx <= maxi; inx++)
		coun[inx] += coun[inx - 1];
	print_array(coun, maxi + 1);

	for (j = 0; j < size; ++j)
	{
		t[coun[array[j]] - 1] = array[j];
		coun[array[j]]--;
	}

	for (j = 0; j < size; j++)
		array[j] = t[j];
	free(t);
	free(coun);

}
