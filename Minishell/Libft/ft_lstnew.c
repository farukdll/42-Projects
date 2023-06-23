#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = malloc(sizeof(t_list));
	if (!t)
		return (0);
	t->content = content;
	t->next = 0;
	return (t);
}
