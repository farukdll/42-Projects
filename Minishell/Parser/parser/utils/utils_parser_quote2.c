#include "parser_utils.h"

char	*parser_qoute_span(char *str, int *index, char c)
{
	char	*tmp;

	tmp = ft_substr(&str[*index], 0, \
	ft_get_chrindex(&str[*index + 1], c) + (1 + (c != ' ')));
	*index += ft_get_chrindex(&str[*index + 1], c) + (1 + (c != ' '));
	return (tmp);
}

char	*parser_qoute_join(char *dst, const char *src, int *index, char c)
{
	int		len;
	char	*tmp;

	len = ft_get_chrindex(&src[*index + 1], c) + (1 + (c != ' '));
	tmp = ft_substr(&src[*index], 0, len);
	dst = ft_free_strjoin(dst, ft_substr(&src[*index], 0, len));
	*index += len;
	return (dst);
}
