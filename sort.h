#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void sp_n(listint_t *r, listint_t *d);
void selection_sort(int *array, size_t size);
void s_n(int *arr, size_t sz1, int *r, int *d);
size_t lomuto_partition(int *array, size_t fz, ssize_t ls, ssize_t ho);
void qu_so_me(int *array, size_t fz, ssize_t ls, ssize_t ho);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
listint_t *sw_no(listint_t *no, listint_t **list);

#endif
