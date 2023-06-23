#ifndef MINISHELL_H
# define MINISHELL_H

# include "Parser/parser/utils/parser_utils.h"
# include "Parser/interpreter/minishell_interpreter.h"
# include "Builtins/minishell_builtins.h"
# include "Libft/libft.h"
# include <fcntl.h>

extern t_vars	g_data;

t_syntax_tree	*build_exec(char *arg_command);
t_syntax_tree	*new_list(t_arg *args);
t_syntax_tree	*new_s_syntax_tree(int type);
t_command		*new_s_command(char **command);
t_redirection	*new_s_redirection(char *redir, char *args);
t_syntax_tree	*new_tree(t_arg *args);

void			executer(t_syntax_tree *command_line);
void			sig_handler(int sig_num);
void			sig_handler_heredoc(int sig_num);
void			del_list(t_syntax_tree **list);
void			del_s_syntax_tree(t_syntax_tree *del);
void			del_s_command(t_command *del);
void			del_s_redirection(t_redirection *del);
void			ft_heredoc(char *arg);
void			all_heredocs(t_syntax_tree *tree);
void			isheredoc(t_syntax_tree *tree);
void			all_redirs(t_syntax_tree *tree);
void			before_execve(t_syntax_tree *right);
void			dup_files(int *fd);
void			path_operations(char **cmd_path, t_syntax_tree *left);
void			voyage_on_tree(t_syntax_tree *tree);
void			before_execute(t_syntax_tree *tree);

int				command_w_path(char **command);
int				ctrl_d(void);
void			ctrl_c(int sig);
int				redirection(t_syntax_tree *tree);
int				ft_space_cntrl(const char *str);
int				ft_qouete_cntrl(const char *str, char c);

char			*get_path(char **env);
char			*get_cmd(char *cmd, char *path);

int				ft_strcmp(char *str1, char *str2);
int				ft_filesize(t_redirection *lst);
int				ft_errors(int err_num);
int				ft_matrix_size(char **matrix);
int				ft_freeall(void *arg);

int				is_redir(char *str);

char			*ft_str_clearspace2(const char *str);

void			build_redirection(t_redirection **redir, char	**cmd);
void			build_add_redirection(char *arg, char *type, \
	t_redirection **redir, int *check_redir);
char			*build_typer(char *str, int *index, int *check_redir);
char			*build_arger(char *str, int *index, int *check_redir);

void			build_command(t_command	**command, char **cmd);

char			*build_quote(char *str, int *index);
char			*build_quote_join(char *str, int *index);

int				which_builtin(char **command);
int				is_builtin(char *cmd);

void			ft_lstadd_back_redir(t_redirection **redir, t_redirection *new);
int				ft_quote_cntrl(const char *str, char c);
void			dup_outfile(int fd_out);
void			dup_infile(int fd_in);
void			main_process(int *fd);
void			catch_childs_exit(void);
int				check_arger(char **cmd, int idx);

#endif