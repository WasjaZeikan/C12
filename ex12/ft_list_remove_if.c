#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*next;
	t_list	*prev;

	if (begin_list == NULL)
		return ;
	curr = *begin_list;
	prev = NULL;
	while (curr)
	{
		next = curr->next;
		if (cmp(curr->data, data_ref) == 0)
		{
			if (curr == *begin_list)
				*begin_list = next;
			if (prev)
				prev->next = next;
			free_fct(curr->data);
			free(curr);
		}
		else
		{
			prev = curr;
		}
		curr = next;
	}
}