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
	listint_t *before;
	size_t len, i, j;

	len = listint_len(*list);
	if (len < 2)
	{
		return;
	}
	i = 0;
	while (i < len)
	{
		j = 1;
		while (j < (len - 1))
		{
			current = get_dnodeint_at_index(*list, j);
			before = get_dnodeint_at_index(*list, (j - 1));
			if (current->n < before->n)
			{
				swap_node(list, before, current);
				print_list(*list);
			}
			j = j + 1;
		}
		i = i + 1;
	}
}

/**
 * swap_node - swapping two nodes
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
	if (a_node->next != NULL)
	{
		a_node->next->prev = a_node;
	}
	if (a_node->prev == NULL)
	{
		*head = b_node;
	}
	a_node->prev = b_node;
	b_node->next = a_node;
	b_node->prev = a_prev;
}

/**
 * get_dnodeint_at_index - accesses given node number
 * @head: pointer to the double linked list
 * @index: the number of requested node
 * Return: addess of given node
 */
listint_t *get_dnodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *ptr;
	unsigned int counter;

	if (head == NULL)
	{
		return (NULL);
	}

	ptr = head;
	counter = 0;

	while (counter < index)
	{
		if (ptr == NULL)
		{
			return (NULL);
		}

		counter = counter + 1;
		ptr = ptr->next;

	}
	return (ptr);
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

