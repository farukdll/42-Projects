#include "minishell_builtins.h"

void	command_unset_exp(char ***matrix, char *unset)
{
	int		len;
	int		find_line;
	char	*var_name;

	if (ft_strchr(unset, '='))
		var_name = ft_substr(unset, 0, ft_strchr(unset, '=') - unset);
	else
		var_name = ft_strjoin(unset, "=");
	len = ft_strlen(var_name);
	find_line = find_line_char_matrix(*matrix, var_name, EXP_LIST, len);
	if (find_line != -1)
	{
		del_line_char_matrix(matrix, find_line);
	}
	else
	{
		len = ft_strlen(unset) + 1;
		find_line = find_line_char_matrix(*matrix, unset, EXP_LIST, len);
		if (find_line != -1)
			del_line_char_matrix(matrix, find_line);
	}
	free(var_name);
}

void	command_unset_env(char ***matrix, char *unset)
{
	int		len;
	int		find_line;
	char	*var_name;

	var_name = ft_strjoin(unset, "=");
	len = ft_strlen(var_name);
	find_line = find_line_char_matrix(*matrix, var_name, ENV_LIST, len);
	if (find_line != -1)
		del_line_char_matrix(matrix, find_line);
	free(var_name);
}

int	command_unset(char ***env_list, char ***exp_list, char *unset)
{
	if (check_unset_export_var(unset, COM_UNS) == -1)
		return (1);
	command_unset_env(env_list, unset);
	command_unset_exp(exp_list, unset);
	return (0);
}

int	multiple_unset(char ***env_list, char ***exp_list, char **unset)
{
	int	line;
	int	exit;

	line = 0;
	exit = 0;
	while (unset[++line])
	{
		if (exit == 0)
			exit = command_unset(env_list, exp_list, unset[line]);
		else
			command_unset(env_list, exp_list, unset[line]);
	}
	return (exit);
}
