#include "minishell_builtins.h"

int	command_echo(char **str)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (str[++i] && !ft_strncmp(str[i], "-n", 3))
		check = 0;
	while (str[i])
		printf("%s ", str[i++]);
	if (check)
		printf("\n");
	return (0);
}
