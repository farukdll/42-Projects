#include "minishell_builtins.h"

void	exp_data_add_quote(char *var_name, char *var_data, char **quote_data)
{
	char	*quote;
	int		i;

	i = -1;
	if (ft_strchr(var_name, '='))
	{
		quote = malloc(ft_strlen(var_data) + 3);
		quote[0] = '\"';
		while (var_data[++i])
			quote[i + 1] = var_data[i];
		quote[++i] = '\"';
		quote[++i] = '\0';
		quote_data[0] = quote;
	}
	else
		*quote_data = NULL;
}

void	command_export_env(char ***env_list, char *var_name, char *var_data)
{
	char	*export;
	char	*var_name2;

	if (!ft_strchr(var_name, '='))
		return ;
	if (var_name == NULL || *var_data == '\0')
		export = ft_strdup(var_name);
	else
		export = ft_strjoin(var_name, var_data);
	var_name2 = ft_strtrim(var_name, "=");
	command_unset_env(env_list, var_name2);
	add_line_char_matrix(env_list, export, count_line(*env_list));
	free_two_str(&export, &var_name2);
}

void	command_export_exp(char ***exp_list, char *var_name, char *var_data)
{
	char	*export;
	char	*quote_data;

	exp_data_add_quote(var_name, var_data, &quote_data);
	if (quote_data == NULL)
		export = ft_strdup(var_name);
	else
		export = ft_strjoin(var_name, quote_data);
	command_unset_exp(exp_list, var_name);
	add_line_char_matrix(exp_list, export, 0);
	add_declare_char_matrix(exp_list);
	ft_sort_params(exp_list);
	if (quote_data)
		free(quote_data);
	free(export);
}

int	command_export(char ***exp_list, char ***env_list, char *export)
{
	char	*var_name;
	char	*var_data;

	if (ft_strchr(export, '='))
	{
		var_name = get_var_name(export);
		var_data = get_var_data(export);
	}
	else
	{
		var_name = ft_strdup(export);
		var_data = NULL;
	}
	if (check_unset_export_var(var_name, COM_EXP) == 0)
	{
		command_export_exp(exp_list, var_name, var_data);
		command_export_env(env_list, var_name, var_data);
	}
	else
	{
		free_two_str(&var_data, &var_name);
		return (1);
	}
	free_two_str(&var_data, &var_name);
	return (0);
}

int	multiple_export(char ***exp_list, char ***env_list, char **export)
{
	int	line;
	int	exit;

	line = 0;
	exit = 0;
	if (!export[1])
	{
		add_declare_char_matrix(exp_list);
		print_line(*exp_list);
	}
	else
	{
		while (export[++line])
		{
			if (exit == 0)
				exit = command_export(exp_list, env_list, export[line]);
			else
				command_export(exp_list, env_list, export[line]);
		}
	}
	return (exit);
}
