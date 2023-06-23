/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_return_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpektas <fpektas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:40:33 by fpektas           #+#    #+#             */
/*   Updated: 2023/01/09 17:05:30 by fpektas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_interpreter.h"

char	*ft_retvalue(int value)
{
	int		i;
	int		val;
	char	*ret;

	ret = ft_calloc(5, sizeof(char));
	i = 0;
	if (value < 0)
	{
		ret[i++] = '-';
		value = -value;
	}
	val = value;
	while (val)
	{
		val /= 10;
		i++;
	}
	while (value)
	{
		ret[--i] = value % 10 + '0';
		value /= 10;
	}
	return (ret);
}
