#include "sort.h"

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
