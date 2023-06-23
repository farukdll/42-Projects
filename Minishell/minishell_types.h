#ifndef MINISHELL_TYPES_H
# define MINISHELL_TYPES_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>

# define ERR_RET 0

# define ERR_MSG_SYNTAX "Error: Syntax Error "

# define PIPE 1
# define COMMAND 2
# define EXEC 3
# define REDIR 4
# define LAST 10

typedef struct s_redirection
{
	char					*redir;
	char					*args;
	int						her_index;
	int						in_index;
	int						out_index;
	struct s_redirection	*next;
}	t_redirection;

typedef struct s_command
{
	char	**command;
}	t_command;

typedef struct s_arg
{
	char	**arg_commands;
	int		cmd_count;
}	t_arg;

typedef struct s_syntax_tree
{
	int						type;
	t_command				*s_command;
	t_redirection			*s_redir;
	struct s_syntax_tree	*left;
	struct s_syntax_tree	*right;
	struct s_syntax_tree	*prev;
}	t_syntax_tree;

typedef struct s_vars
{
	pid_t	dup_in;
	pid_t	dup_out;
	char	**env;
	char	**export;
	char	*path;
	char	*cmd_path;
	int		ret_signal;
	int		interrupt;
	int		redir_val;
	int		*infiles;
	int		*outfiles;
	int		**heredoc;
	int		ref_her;
	int		fd[2][2];
	int		cmd;
	int		pipe;
	int		cmd_count;
	int		count_in;
	int		count_out;
	int		count_her;
	pid_t	*pids;
	int		exit_num;
	int		syntax_err;
}	t_vars;

typedef struct s_redir_var
{
	int		idx;
	int		n_idx;
	int		k_idx;
	int		last_idx;
	int		arr_idx;
	int		len;
	int		arg_len;
	char	*cmd;
	char	*arg;
}	t_redir_var;

typedef struct s_redirection_var
{
	int		c_redir;
	char	*type;
	char	*arg;
	int		idx;
}	t_redirection_var;

#endif