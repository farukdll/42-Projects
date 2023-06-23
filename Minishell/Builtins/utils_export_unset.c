#include "minishell_builtins.h"

int	check_unset_export_var(char *unset, char sep)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(unset[0]) || unset[0] == '_'))
	{
		if (sep == COM_UNS)
			printf("unset: `%s': not a valid identifier\n", unset);
		else if (sep == COM_EXP)
			printf("export: `%s': not a valid identifier\n", unset);
		return (-1);
	}
	while (unset[++i])
	{
		if (!(ft_isalpha(unset[i]) || unset[i] == '_' || ft_isdigit(unset[i])))
		{
			if (sep == COM_EXP && unset[i] == '=' && unset[i + 1] == '\0')
				break ;
			if (sep == COM_UNS)
				printf("unset: `%s': not a valid identifier\n", unset);
			else if (sep == COM_EXP)
				printf("export: `%s': not a valid identifier\n", unset);
			return (-1);
		}
	}
	return (0);
}

int	find_line_char_matrix(char **matrix, char *find_line, char sep, size_t n)
{
	int	jump_indis;
	int	tot_line;
	int	line;

	if (sep == ENV_LIST)
		jump_indis = 0;
	else if (sep == EXP_LIST)
		jump_indis = 11;
	tot_line = count_line(matrix);
	line = -1;
	while (++line < tot_line)
	{
		if (ft_strncmp(&(matrix[line][jump_indis]), find_line, n) == 0)
			break ;
	}
	if (line == tot_line)
		return (-1);
	return (line);
}

void	add_line_char_matrix(char ***matrix, char *add, int add_line)
{
	char	**new;
	int		tot_line;
	int		new_i;
	int		matrix_i;

	new_i = 0;
	matrix_i = 0;
	tot_line = count_line(matrix[0]);
	new = (char **)malloc(sizeof(char *) * (tot_line + 2));
	while (matrix_i < tot_line)
	{
		if (new_i == add_line)
			new[new_i] = ft_strdup(add);
		else
			new[new_i] = ft_strdup(matrix[0][matrix_i++]);
		new_i++;
	}
	if (add_line == tot_line)
		new[new_i++] = ft_strdup(add);
	new[new_i] = NULL;
	free_char_matrix(matrix);
	*matrix = new;
}

void	del_line_char_matrix(char ***matrix, int del_line)
{
	char	**new;
	int		tot_line;
	int		new_i;
	int		matrix_i;

	new_i = 0;
	matrix_i = 0;
	tot_line = count_line(matrix[0]);
	new = (char **)malloc(sizeof(char *) * tot_line);
	while (new_i < tot_line -1)
	{
		if (matrix_i != del_line)
			new[new_i++] = ft_strdup(matrix[0][matrix_i]);
		matrix_i++;
	}
	new[new_i] = NULL;
	free_char_matrix(matrix);
	*matrix = new;
}

void	add_declare_char_matrix(char ***matrix)
{
	char	**exp_list;
	char	*declare;
	int		tot_line;
	int		line;

	tot_line = count_line(matrix[0]);
	line = -1;
	declare = ft_strdup("declare -x ");
	exp_list = (char **)malloc(sizeof(char *) * (tot_line + 1));
	while (++line < tot_line)
	{
		if (ft_strncmp(matrix[0][line], declare, ft_strlen(declare)) == 0)
		{
			exp_list[line] = ft_strdup(matrix[0][line]);
		}
		else
			exp_list[line] = ft_strjoin(declare, matrix[0][line]);
	}
	free_char_matrix(matrix);
	free(declare);
	exp_list[line] = NULL;
	matrix[0] = exp_list;
}
