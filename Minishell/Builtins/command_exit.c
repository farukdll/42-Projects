#include "minishell_builtins.h"

int	is_full_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	command_exit(char **arg)
{
	int	i;

	i = -1;
	printf("exit\n");
	while (arg[++i])
		;
	if (i > 1)
	{
		if (is_full_digit(arg[1]) == 0)
		{
			printf("exit: %s: numeric argument required", arg[1]);
			exit(255);
		}
		else if (i == 2)
			exit(ft_atoi(arg[1]));
		else
		{
			printf("exit: too many arguments\n");
			return (1);
		}
	}
	else
		exit(0);
	return (0);
}
