/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_qoute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpektas <fpektas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:40:33 by fpektas           #+#    #+#             */
/*   Updated: 2023/01/09 17:05:22 by fpektas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_interpreter.h"

char	*ft_check_quote(const char *str, t_vars *g_data)
{
	char				*tmp[2];
	t_interpreter_quote	v;

	interpreter_qouete_init(str, &v);
	tmp[1] = ft_calloc(sizeof(char), 1);
	while (++v.i < v.len)
	{
		if (str[v.i] == '"' || str[v.i] == '\'')
			tmp[0] = interpreter_qouete(&str[v.i], str[v.i], &v.i, g_data);
		else
		{
			if (str[v.i] == '$')
			{
				tmp[0] = ft_format(&str[v.i + 1], &v.env_len, g_data);
				if (tmp[0] == NULL)
					tmp[0] = ft_strdup("");
				v.i += v.env_len;
			}
			else
				tmp[0] = ft_substr(str, v.i, 1);
		}
		tmp[1] = ft_envjoin(tmp[1], tmp[0]);
	}
	return (tmp[1]);
}

char	*ft_double_quote(const char *str, int *end_index, t_vars *g_data)
{
	int		i;
	int		env_len;
	char	*n_str;
	char	*tmp;

	i = 0;
	env_len = 0;
	n_str = ft_calloc(sizeof(char), 1);
	while (str[i] && str[i] != '"')
	{
		if (str[i] == '$')
		{
			tmp = ft_format(&str[i + 1], &env_len, g_data);
			if (tmp == NULL)
				tmp = ft_strdup("");
			i += ++env_len;
		}
		else
			tmp = ft_substr(str, i++, 1);
		n_str = ft_envjoin(n_str, tmp);
	}
	*end_index += i;
	return (n_str);
}

char	*ft_quote(const char *str, int *end_index)
{
	int		i;
	char	*n_str;
	char	*tmp;

	i = 0;
	n_str = ft_calloc(sizeof(char), 1);
	while (str[i] && str[i] != '\'')
	{
		tmp = ft_substr(str, i++, 1);
		n_str = ft_envjoin(n_str, tmp);
	}
	*end_index += ++i;
	return (n_str);
}

char	*ft_format(const char *str, int *env_len, t_vars *g_data)
{
	t_format_data	v;

	if (*str == '?')
	{
		*env_len = 1;
		return (ft_itoa(g_data->exit_num));
	}
	v.i = ft_is_valid_env(str);
	if (v.i == 0)
		return ((void *)(uintptr_t)ft_set_envlen(env_len, 0));
	v.tmp = ft_substr(str, 0, v.i);
	v.var = ft_strjoin(v.tmp, "=");
	free(v.tmp);
	v.index = ft_get_env(v.var, g_data->env);
	if (v.index > -1)
	{
		*env_len = v.i;
		v.i = ft_strlen(v.var);
		free(v.var);
		v.var = ft_strdup(g_data->env[v.index] + v.i);
		return (v.var);
	}
	*env_len = v.i;
	free(v.var);
	return (NULL);
}

char	*interpreter_qouete(const char *str, char qt, int *idx, t_vars *g_data)
{
	char	*tmp;

	if (qt == '"')
	{
		tmp = ft_double_quote(str + 1, idx, g_data);
		(*idx)++;
	}
	else
		tmp = ft_quote(str + 1, idx);
	tmp = ft_strappend(tmp, qt);
	return (tmp);
}
