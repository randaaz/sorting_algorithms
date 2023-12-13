#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ii, *jj;

	if (!list || !*list || !(*list)->next)
		return;
	ii = (*list)->next;
	while (ii)
	{
		jj = ii;
		ii = ii->next;
		while (jj && jj->prev)
		{
			if (jj->prev->n > jj->n)
			{
				sp_n(jj->prev, jj);
				if (!jj->prev)
					*list = jj;
				print_list((const listint_t *)*list);
			}
			else
				jj = jj->prev;
		}
	}
}

/**
 * sp_n - Function to swap nodes in a doubly linked list
 * @r: Pointer to the first node to be swapped
 * @d: Pointer to the second node to be swapped
 */
void sp_n(listint_t *r, listint_t *d)
{
	if (r->prev)
		r->prev->next = d;
	if (d->next)
		d->next->prev = r;
	r->next = d->next;
	d->prev = r->prev;
	r->prev = d;
	d->next = r;
}
