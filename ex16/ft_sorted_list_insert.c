#include "ft_list.h"

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*curr;
	t_list	*elem;

	if (!begin_list)
		return ;
	curr = *begin_list;
	if (curr == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while (curr->next && cmp(curr->data, data) <= 0)
		curr = curr->next;
	if (cmp(curr->data, data) > 0)
	{
		elem = ft_create_elem(curr->data);
		curr->data = data;
		elem->next = curr->next;
		curr->next = elem;
		return ;
	}
	elem = ft_create_elem(data);
	elem->next = curr->next;
	curr->next = elem;
}