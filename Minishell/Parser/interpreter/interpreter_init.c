/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpektas <fpektas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:40:33 by fpektas           #+#    #+#             */
/*   Updated: 2023/01/09 17:04:59 by fpektas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_interpreter.h"

void	interpreter_qouete_init(const char *str, t_interpreter_quote *v)
{
	v->i = -1;
	v->env_len = 0;
	v->len = ft_strlen(str);
}

int	ft_set_envlen(int *env_len, int val)
{
	*env_len = val;
	return (val);
}
