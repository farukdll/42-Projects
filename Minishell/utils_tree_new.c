#include "minishell.h"

int	is_redir(char *str)
{
	int			i;
	static char	*redir_types[5] = {">>", "<<", ">", "<", 0};

	i = -1;
	while (redir_types[++i])
	{
		if (ft_strncmp(str, redir_types[i], ft_strlen(redir_types[i])) == 0)
			return (ft_strlen(redir_types[i]));
	}
	return (0);
}

int	use_is_redir(char **cmd, int *idx, char **type, int *check_redir)
{
	if (*check_redir == 1)
		return (-1);
	*type = ft_substr(cmd[0], *idx, is_redir(&(cmd[0][*idx])));
	ft_memset(&cmd[0][*idx], ' ', ft_strlen(*type));
	*idx += ft_strlen(*type);
	*check_redir = 1;
	return (0);
}

void	use_is_arg(char **cmd, int *idx, char **arg, int *check_redir)
{
	if (cmd[0][*idx] == '"' || cmd[0][*idx] == '\'')
	{
		*arg = ft_substr(cmd[0], *idx, \
						ft_get_chrindex(&cmd[0][*idx + 1], cmd[0][*idx]) + 1);
	}
	else
	{
		*arg = ft_substr(cmd[0], *idx, \
						ft_get_chrindex(&cmd[0][*idx + 1], ' ') + 1);
	}
	ft_memset(&cmd[0][*idx], ' ', ft_strlen(*arg));
	*idx += ft_strlen(*arg);
	*check_redir = 2;
}

void	build_tree_w_pipe(t_syntax_tree *tree, char **arg_commands, int pipe)
{
	int	i;

	i = 0;
	while (pipe)
	{
		tree->left = build_exec(arg_commands[i]);
		tree->left->prev = tree;
		i++;
		pipe--;
		if (pipe)
		{
			tree->right = new_s_syntax_tree(PIPE);
			tree->right->prev = tree;
		}
		else
		{
			tree->right = build_exec(arg_commands[i]);
			tree->right->prev = tree;
		}
		tree = tree->right;
	}
}

t_syntax_tree	*new_tree(t_arg *args)
{
	t_syntax_tree	*tree;
	int				pipe_count;

	pipe_count = args->cmd_count - 1;
	if (!pipe_count)
		tree = build_exec(args->arg_commands[0]);
	else
	{
		tree = new_s_syntax_tree(PIPE);
		build_tree_w_pipe(tree, args->arg_commands, pipe_count);
	}
	return (tree);
}
