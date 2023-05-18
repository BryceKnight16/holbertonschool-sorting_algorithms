#include "sort.h"

listint_t *get_dnodeint_at_index(listint_t *head, unsigned int index);
void swap_node(listint_t *a_node, listint_t *b_node);
size_t listint_len(const listint_t *h);



/**
 * insertion_sort_list - short description
 * @list: a listint_t **data type variable
 *
 * Return: type is void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head;
	listint_t *current;
	listint_t *after;
	size_t len;
	int i, j;

	head = *list;
	len = listint_len(head);
	if (head == NULL || len < 2)
	{
		return;
	}
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1))
		{
			current = get_dnode_int_at_index(head, j);
			after = get_dnode_int_at_index(head, (j + 1));
			if (current->n > after->n)
			{
				swap_node(current, after);
				print_list(head);
			}
			j = j + 1;
		}
		i = i + 1;
	}
}

/**
 * swap_node - short description
 * @current: a listint_t data type variable
 * @after: a listint_t data type variable
 *
 * Return: type is void
 */

void swap_node(listint_t *a_node, listint_t *b_node)
{
	listint_t *temp;
	
	temp = malloc(sizeof(*temp));
	if (temp == NULL)
	{
		exit(1);
	}
	temp->next = a_node->next;
	temp->prev = a_node->prev;

	a_node->next = b_node->next;
	a_node->prev = b_node;

	b_node->next = a_node;
	b_node->prev = temp->prev;

	if (temp->prev != NULL)
	{
		temp->prev->next = b_node;
	}
	if (a_node->next != NULL)
	{
		a_node->next->prev = a_node;
	}
		free(temp);
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
