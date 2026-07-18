#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
	t_list	*curr;
	t_list	*next;
	t_list	*prev;

	prev = NULL;
	curr = *begin_list;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*begin_list = prev;
}