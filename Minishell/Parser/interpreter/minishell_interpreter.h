/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_interpreter.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpektas <fpektas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:40:33 by fpektas           #+#    #+#             */
/*   Updated: 2023/01/09 17:05:35 by fpektas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_INTERPRETER_H
# define MINISHELL_INTERPRETER_H

# include <stdio.h>
# include "../parser/utils/parser_utils.h"
# include "../../Libft/libft.h"

typedef struct s_interpreter_quote
{
	int	i;
	int	env_len;
	int	len;
}	t_interpreter_quote;

typedef struct s_format_data
{
	int		i;
	int		index;
	char	*tmp;
	char	*var;
}	t_format_data;

char	**interpreter_array_format(char **arr, t_vars *g_data);

char	*ft_check_quote(const char *str, t_vars *g_data);
char	*ft_double_quote(const char *str, int *end_index, t_vars *g_data);
char	*ft_quote(const char *str, int *end_index);
char	*ft_format(const char *str, int	*env_len, t_vars *g_data);
char	*interpreter_qouete(const char *str, char qt, int *idx, t_vars *g_data);

void	interpreter_qouete_init(const char *str, t_interpreter_quote *v);
int		ft_set_envlen(int *env_len, int val);

char	*ft_retvalue(int value);

char	*ft_envjoin(char *dst, char *src);
int		ft_get_env_len(const char *str);
int		ft_get_env(const char *str, char **env);
int		ft_is_valid_env(const char *str);

#endif