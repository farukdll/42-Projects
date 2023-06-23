#ifndef MINISHELL_BUILTINS_H
# define MINISHELL_BUILTINS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

# define EXP_LIST 51
# define ENV_LIST 25
# define COM_EXP 46
# define COM_UNS 2

char	**ft_strdup_multi(char **s1);
void	print_line(char **lines);
int		count_line(char **str);
int		ft_sort_params(char ***argv);
int		free_two_str(char **s1, char **s2);

int		command_cd(char *dir, char ***exp, char ***env);
int		command_echo(char **str);
int		command_exit(char **arg);
int		command_pwd(void);
int		command_env(char **env);

int		check_unset_export_var(char *unset, char sep);

void	command_unset_env(char ***matrix, char *unset);
void	command_unset_exp(char ***matrix, char *unset);
int		command_unset(char ***env_list, char ***exp_list, char *unset);
int		multiple_unset(char ***env_list, char ***exp_list, char **unset);

void	command_export_env(char ***env_list, char *var_name, char *var_data);
void	command_export_exp(char ***exp_list, char *var_name, char *var_data);
int		command_export(char ***exp_list, char ***env_list, char *export);
int		multiple_export(char ***exp_list, char ***env_list, char **export);

void	add_declare_char_matrix(char ***matrix);
void	del_line_char_matrix(char ***matrix, int del_line);
void	add_line_char_matrix(char ***matrix, char *add, int add_line);
void	free_char_matrix(char ***matrix);
int		find_line_char_matrix(char **matrix, char *line, char sep, size_t n);

void	exp_data_add_quote(char *var_name, char *var_data, char **quote_data);
char	*get_var_data(char *env);
char	*get_var_name(char *env);
char	**set_export_quote(char **export);

#endif