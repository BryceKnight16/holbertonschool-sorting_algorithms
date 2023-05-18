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
			current = get_dnode_int_at_index(listint_t head, 
			if ()
			j = j + 1;
		}
		i = i + 1;
	}
}
