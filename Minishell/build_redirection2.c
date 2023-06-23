#include "minishell.h"

int	check_arger(char **cmd, int idx)
{
	if (is_redir(&cmd[0][idx]))
	{
		g_data.syntax_err = 1;
		return (0);
	}
	else if (cmd[0][idx] != ' ')
		return (1);
	return (0);
}
