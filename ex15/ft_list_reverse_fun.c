#include "ft_list.h"
#include <stddef.h>

size_t ft_list_size(t_list *begin_list)
{
	size_t	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

t_list	*ft_list_at(t_list *begin_list, size_t nbr)
{
	while (begin_list && nbr--)
		begin_list = begin_list->next;
	return (begin_list);
}

void ft_list_reverse_fun(t_list *begin_list)
{
	size_t		size;
	int			i;
	t_list		*front;
	t_list		*back;
	void		*temp;

	if (!begin_list)
		return ;
	size = ft_list_size(begin_list);
	i = 0;
	while (i < size / 2)
	{
		front = ft_list_at(begin_list, i);
		back = ft_list_at(begin_list, size - 1 - i);
		temp = front->data;
		front->data = back->data;
		back->data = temp;
		i++;
	}
}