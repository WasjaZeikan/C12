#include "ft_list.h"

t_list *ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*head;
	t_list	*curr;

	if (size <= 0)
		return (NULL);
	i = size - 1;
	head = ft_create_elem(strs[i]);
	curr = head;
	i--;
	while (i >= 0)
	{
		curr->next = ft_create_elem(strs[i]);
		curr = curr->next;
		i--;
	}
	return (head);
}