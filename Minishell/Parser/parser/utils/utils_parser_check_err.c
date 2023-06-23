#include "parser_utils.h"

t_vars	g_data;

int	ft_space_cntrl(const char *str);
int	ft_quote_cntrl(const char *str, char c);

void	*parser_check_error(char *str)
{
	if (!ft_strlen(str) || ft_space_cntrl(str))
		return (NULL);
	if (parser_check_quotes(str) == 0)
	{
		ft_error("qoute error", NULL, ERR_RET);
		return (NULL);
	}
	if (parser_check_qoute_error(str) == 0)
		return (NULL);
	if (parser_check_perr(str) == 0)
		return (NULL);
	return ((void *)1);
}

int	parser_check_qoute_error(char *str)
{
	if (ft_quote_cntrl(str, '\'') || ft_quote_cntrl(str, '"'))
	{
		printf("command not found\n");
		g_data.exit_num = 127;
		return (0);
	}
	return (1);
}

int	parser_check_perr(char *str)
{
	if (ft_strlen(str) == 3 && str[0] == 39 && str[2] == 39 && str[1] == 124)
	{
		printf("|: command not found\n");
		g_data.exit_num = 127;
		return (0);
	}
	return (1);
}
