#include "../parser_utils.h"

size_t	ft_wordlen(char *str, char **arr)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (*str == '"' || *str == '\'')
		i = parser_quote_endidx(str + 1, *str);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ' && parser_array_cmp(&str[i], arr) == -1)
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			i += parser_quote_endidx(&str[i + 1], str[i]);
			len += parser_quote_endidx(&str[i + 1], str[i]);
		}
		else
			i++;
	}
	return (i);
}

char	*ft_get_next_word(char *str, char **arr)
{
	int		i;
	int		n;
	char	*tmp;

	tmp = malloc(sizeof(char) * ft_wordlen(str, arr) + 1);
	i = 0;
	n = 0;
	if (*str == '"' || *str == '\'')
		i = parser_quote_endidx(str + 1,*str) + 1;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ' && parser_array_cmp(&str[i], arr) == -1)
		tmp[n++] = str[i++];
	tmp[n] = '\0';
	return (tmp);
}
