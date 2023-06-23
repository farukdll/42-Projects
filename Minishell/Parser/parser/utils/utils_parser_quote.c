#include "parser_utils.h"

int	parser_quote_endidx(const char *str, char c)
{
	return (ft_get_chrindex(str, c));
}

int	parser_check_quotes(char *str)
{
	int	i;
	int	count_quote;
	int	count_dquate;

	i = 0;
	count_quote = 0;
	count_dquate = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			if (i == 0 || (i > 0 && str[i - 1] != '\\'))
				i += parser_check_doublequote(&str[i + 1], \
					&count_dquate, &count_quote);
		}
		else if (str[i] == '\'')
		{
			if (i == 0 || (i > 0 && str[i - 1] != '\\'))
				i += parser_check_quote(&str[i + 1], &count_quote);
		}
		i++;
	}
	return (count_dquate % 2 == 0 && count_quote % 2 == 0);
}

int	parser_check_doublequote(char *str, int *count_dquote, int *count_quote)
{
	int	i;

	i = 0;
	(*count_dquote)++;
	(void)count_quote;
	while (str[i])
	{
		if (str[i] == '"')
		{
			if (i == 0 || (i > 0 && str[i - 1] != '\\'))
			{
				(*count_dquote)++;
				break ;
			}
		}
		i++;
	}
	return (++i);
}

int	parser_check_quote(char *str, int *count_quote)
{
	int	i;

	i = 0;
	(*count_quote)++;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (i == 0 || (i > 0 && str[i - 1] != '\\'))
			{
				(*count_quote)++;
				break ;
			}
		}
		i++;
	}
	return (++i);
}

char	**parser_array_clearquotes(char **arr)
{
	int		i;
	char	*tmp;

	i = 0;
	while (arr[i])
	{
		tmp = ft_calloc(ft_strlen(arr[i]) + 1, sizeof(char));
		tmp = ft_str_clearquotes(arr[i], tmp);
		free(arr[i]);
		arr[i] = tmp;
		i++;
	}
	return (arr);
}
