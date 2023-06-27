#include "sort.h"
/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	print_list(*list);
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker sort algorithm
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left = *list, *right = NULL, *curr = NULL;
	int swapped = 1;

	if (!list || !(*list) || !(*list)->next)
		return;
	while (swapped)
	{
		swapped = 0;
		while (left->next != right)
		{
			curr = left;
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				swapped = 1;
			}
			else
				left = left->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		right = left;
		while (right->prev != NULL)
		{
			curr = right->prev;
			if (curr->n > right->n)
			{
				swap_nodes(list, curr, right);
				swapped = 1;
			}
			else
				right = right->prev;
		}
		left = right;
	}
}
