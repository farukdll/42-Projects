#include "minishell.h"

void	build_add_redirection(char *arg, char *type, t_redirection **redir, \
	int *check_redir)
{
	char	*ptr;
	char	*tmp;

	ptr = ft_calloc(sizeof(char) * (ft_strlen(arg) + 1), sizeof(char));
	tmp = ft_str_clearquotes(arg, ptr);
	ft_lstadd_back_redir(redir, new_s_redirection(type, tmp));
	free(arg);
	*check_redir = 0;
}

char	*build_typer(char *str, int *index, int *check_redir)
{
	char	*tmp;

	tmp = ft_substr(str, *index, is_redir(&(str[*index])));
	ft_memset(&str[*index], ' ', ft_strlen(tmp));
	*index += ft_strlen(tmp);
	*check_redir = 1;
	return (tmp);
}

char	*build_arger(char *str, int *index, int *check_redir)
{
	int		start_index;
	char	*tmp;

	start_index = *index;
	if (str[*index] == '"' || str[*index] == '\'')
	{
		tmp = build_quote(str, index);
		ft_memset(&str[start_index], ' ', *index - start_index);
		(*index)--;
	}
	else
	{
		while (str[*index] && (str[*index] != ' ' && !is_redir(&str[*index])))
			(*index)++;
		tmp = ft_substr(str, start_index, *index - start_index);
		ft_memset(&str[start_index], ' ', ft_strlen(tmp));
		(*index)--;
	}
	if (*tmp == '\0')
		return (NULL);
	else
		*check_redir = 2;
	return (tmp);
}

void	build_redirection_sub(t_redirection **redir, t_redirection_var *v)
{
	if (v->c_redir == 1)
	{
		g_data.syntax_err = 1;
		printf("syntax error\n");
	}
	if (!*redir)
		*redir = NULL;
}

void	build_redirection(t_redirection **redir, char	**cmd)
{
	t_redirection_var	v;

	v.idx = -1;
	v.c_redir = 0;
	g_data.syntax_err = 0;
	while (++v.idx < (int)ft_strlen(cmd[0]))
	{
		if (v.c_redir == 0 && (cmd[0][v.idx] == '"' || cmd[0][v.idx] == '\''))
			v.idx += ft_strchr(&(cmd[0][v.idx + 1]), \
				cmd[0][v.idx]) - &(cmd[0][v.idx]);
		if (is_redir(&(cmd[0][v.idx])))
			v.type = build_typer(cmd[0], &v.idx, &v.c_redir);
		if (v.c_redir == 1 && check_arger(cmd, v.idx))
			v.arg = build_arger(cmd[0], &v.idx, &v.c_redir);
		if (v.c_redir == 2)
		{
			build_add_redirection(v.arg, v.type, redir, &v.c_redir);
			v.type = NULL;
			v.arg = NULL;
		}
	}
	build_redirection_sub(redir, &v);
}
