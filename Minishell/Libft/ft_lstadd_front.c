#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		new -> next = 0;
	else
		new -> next = *lst;
	*lst = new;
}
