#include "parser_utils.h"

char	**parser_array_trim(char **str)
{
	char	**ret;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	ret = (char **)malloc(sizeof(char **) * parser_array_getsize(str) + 1);
	while (str[i])
	{
		ret[i] = ft_strtrim(str[i], " ");
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	parser_array_cmp(char *str, char **arr)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (arr[i])
	{
		if (ft_strncmp(str, arr[i], ft_strlen(arr[i])) == 0)
		{
			if (str[ft_strlen(arr[i])] != arr[i][0])
				return (i);
		}
		i++;
	}
	return (-1);
}

int	parser_array_getsize(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	parser_check_valid_syntax(char **str, char **arr)
{
	int	i;
	int	j;
	int	arr_idx;

	i = 0;
	arr_idx = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			arr_idx = parser_array_cmp(&str[i][j++], arr);
			if (arr_idx > -1)
				j += ft_strlen(arr[arr_idx]);
		}
		if (arr_idx > -1)
			if (ft_strncmp((str[i] + ft_strlen(str[i])) - ft_strlen \
				(arr[arr_idx]), arr[arr_idx], ft_strlen(arr[arr_idx])) == 0)
				return (ft_error(ERR_MSG_SYNTAX, arr[arr_idx], ERR_RET));
		i++;
	}
	return (1);
}
