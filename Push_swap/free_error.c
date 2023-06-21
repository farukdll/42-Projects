#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
	return (0);
}
