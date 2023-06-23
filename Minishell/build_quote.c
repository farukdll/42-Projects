#include "minishell.h"

char	*build_quote_join(char *str, int *index)
{
	int		i;
	char	*tmp;
	char	*n_str;
	int		len;

	i = 0;
	n_str = malloc(sizeof(char));
	*n_str = '\0';
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			len = parser_quote_endidx(&str[i + 1], str[i]);
			tmp = ft_substr(&str[i + 1], 0, len);
			n_str = ft_free_strjoin(n_str, tmp);
			i += len + 2;
			free(tmp);
		}
		else
			break ;
	}
	*index += i;
	return (n_str);
}

char	*build_quote(char *str, int *index)
{
	char	*tmp;
	char	*n_str;
	char	quote;

	n_str = ft_calloc(1, sizeof(char));
	while (str[*index])
	{
		if (str[*index] == '"' || str[*index] == '\'')
		{
			quote = str[*index];
			tmp = build_quote_join(&str[*index], index);
			n_str = ft_free_strjoin(n_str, tmp);
			n_str = ft_strappend(n_str, quote);
			free(tmp);
		}
		else if (str[*index] != ' ' && !is_redir(&str[*index]))
		{
			n_str = ft_free_strjoin(n_str, ft_substr(str, *index, 1));
			n_str = ft_strappend(n_str, '"');
			(*index)++;
		}
		else
			break ;
	}
	return (n_str);
}
