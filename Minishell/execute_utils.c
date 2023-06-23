#include "minishell.h"

void	before_execve(t_syntax_tree *right)
{
	if (g_data.cmd < g_data.cmd_count - 1)
		dup_files(g_data.fd[g_data.pipe]);
	g_data.pipe++;
	if (right)
		g_data.redir_val = redirection(right);
}

int	is_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5) || !ft_strncmp(cmd, "env", 4)
		||!ft_strncmp(cmd, "pwd", 4) || !ft_strncmp(cmd, "export", 7)
		||!ft_strncmp(cmd, "unset", 6) || !ft_strncmp(cmd, "cd", 3)
		||!ft_strncmp(cmd, "exit", 5))
		return (1);
	return (0);
}

int	which_builtin(char **command)
{
	int	exit;

	exit = 0;
	if (!ft_strncmp(command[0], "echo", 5))
		exit = command_echo(command);
	else if (!ft_strncmp(command[0], "env", 4))
		exit = command_env(g_data.env);
	else if (!ft_strncmp(command[0], "pwd", 4))
		exit = command_pwd();
	else if (!ft_strncmp(command[0], "export", 7))
		exit = multiple_export(&g_data.export, &g_data.env, command);
	else if (!ft_strncmp(command[0], "unset", 6))
		exit = multiple_unset(&g_data.env, &g_data.export, command);
	else if (!ft_strncmp(command[0], "cd", 3))
		exit = command_cd(command[1], &g_data.export, &g_data.env);
	else if (!ft_strncmp(command[0], "exit", 5))
		exit = command_exit(command);
	return (exit);
}

void	path_operations(char **cmd_path, t_syntax_tree *left)
{
	char	*path;

	path = get_path(g_data.env);
	*cmd_path = get_cmd(left->s_command->command[0], path);
	free(path);
	if (!(*cmd_path))
	{
		write (2, left->s_command->command[0],
			ft_strlen(left->s_command->command[0]));
		write(2, ": command not found\n", 20);
		g_data.exit_num = 127;
		exit(g_data.exit_num);
	}
}

void	voyage_on_tree(t_syntax_tree *tree)
{
	if (!tree->left)
		redirection(tree->right);
	else
		before_execute(tree);
}
