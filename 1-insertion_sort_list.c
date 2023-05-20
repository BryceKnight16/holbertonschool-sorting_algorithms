#include "sort.h"

/**
 * insertion_sort_list - short description
 * @list: a listint_t **data type variable
 *
 * Return: type is void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *after;

	if (list == NULL || *list == NULL || listint_len(*list) < 2)
	{
		return;
	}
	current = *list;
	while (current->next != NULL)
	{
		after = current->next;
		if (current->n > after->n)
		{
			swap_node(list, current, after);
			print_list(*list);
			current = *list;
		}
		else
		{
			current = current->next;
		}
	}
}

/**
 * swap_node - swapping two nodes
 * @head: double pointer to a listint_t data type variable
 * @a_node: a listint_t data type variable
 * @b_node: a listint_t data type variable
 *
 * Return: type is void
 */

void swap_node(listint_t **head, listint_t *a_node, listint_t *b_node)
{
	listint_t *a_prev;

	a_prev = a_node->prev;
	a_node->next = b_node->next;
	if (b_node->next != NULL)
	{
		b_node->next->prev = a_node;
	}
	if (a_node->prev == NULL)
	{
		*head = b_node;
	}
	else
	{
		a_node->prev->next = b_node;
	}
	a_node->prev = b_node;
	b_node->next = a_node;
	b_node->prev = a_prev;
}

/**
 * listint_len - returns the number of elements of a list_t list
 *
 * @h: elements of the list
 *
 * Return: size_t number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t counter;

	counter = 0;
	while (h != NULL)
	{
		h = h->next;
		counter = counter + 1;
	}
	return (counter);
}
