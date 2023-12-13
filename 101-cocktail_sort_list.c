#include "sort.h"
#include <stdio.h>

/**
 * sw_no - Function to swap a node with its previous node in a linked list
 * @no: Pointer to the node to be swapped
 * @list: Pointer to the head of the linked list
 *
 * Return: Pointer to the swapped node
 */
listint_t *sw_no(listint_t *no, listint_t **list)
{
	listint_t *bk = no->prev, *cur = no;


	bk->next = cur->next;
	if (cur->next)
		cur->next->prev = bk;
	cur->next = bk;
	cur->prev = bk->prev;
	bk->prev = cur;
	if (cur->prev)
		cur->prev->next = cur;
	else
		*list = cur;
	return (cur);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail Shaker
 *(Bidirectional Bubble Sort) algorithm.
 * @list: Double pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *no;
	int sw_do = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	no = *list;
	while (sw_do == 1)
	{
		sw_do = 0;
		while (no->next)
		{
			if (no->n > no->next->n)
			{
				no = sw_no(no->next, list);
				sw_do = 1;
				print_list(*list);
			}
			no = no->next;
		}
		if (sw_do == 0)
			break;
		sw_do = 0;
		while (no->prev)
		{
			if (no->n < no->prev->n)
			{
				no = sw_no(no, list);
				sw_do = 1;
				print_list(*list);
			}
			else
				no = no->prev;
		}
	}
}
