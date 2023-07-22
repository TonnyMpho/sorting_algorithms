#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - function that swaps two linked list nodes
 * @list: pointer doubly linked list
 * @node_1: first node to swap
 * @node_2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node_1, listint_t *node_2)
{
	if (node_1->prev != NULL)
		node_1->prev->next = node_2;
	else
		*list = node_2;

	node_1->next = node_2->next;
	node_2->prev = node_1->prev;
	node_2->next = node_1;
	node_1->prev = node_2;

	if (node_2->next != NULL)
		node_2->next->prev = node_1;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort
 * algorithm
 *
 * @list: pointer to the doubly linked list
 * Return: Nothing (Void)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node = *list;
	listint_t *next_node;

	if (*list == NULL || (*list)->next == NULL)
		return;

	next_node = (*list)->next;

	while (next_node)
	{
		curr_node = next_node;

		while (curr_node->prev && curr_node->prev->n > curr_node->n)
		{
			swap_nodes(list, curr_node->prev, curr_node);
			print_list(*list);
		}
		next_node = next_node->next;
	}
}
