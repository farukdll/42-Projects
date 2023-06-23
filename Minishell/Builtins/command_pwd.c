#include "minishell_builtins.h"

int	command_pwd(void)
{
	int		exit;
	char	*str;

	exit = 0;
	str = getcwd(NULL, 0);
	printf("%s\n", str);
	free(str);
	return (exit);
}
