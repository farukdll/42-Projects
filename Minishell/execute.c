#include "minishell.h"

void	catch_childs_exit(void)
{
	int	i;

	i = 0;
	while (i < g_data.cmd_count)
	{
		waitpid(g_data.pids[i], &g_data.exit_num, 0);
		if (WIFEXITED(g_data.exit_num))
			g_data.exit_num /= 256;
		if (g_data.exit_num == 3 || g_data.exit_num == 2)
			g_data.exit_num += 128 ;
		i++;
	}
}

void	ft_executable_file(t_syntax_tree *left, t_syntax_tree *right)
{
	(void)right;
	if (!ft_strncmp(left->s_command->command[0], "./", 2))
		execve(left->s_command->command[0], \
			ft_split(ft_strchr(left->s_command->command[0], '/') + \
				1, ' '), g_data.env);
}

void	child_process(t_syntax_tree *left, t_syntax_tree *right)
{
	char	*cmd_path;

	if (is_builtin(left->s_command->command[0]))
	{
		before_execve(right);
		exit(which_builtin(left->s_command->command));
	}
	else
	{
		ft_executable_file(left, right);
		if (ft_strrchr(left->s_command->command[0], '/'))
		{
			if (!command_w_path(left->s_command->command))
				exit(g_data.exit_num);
		}
		path_operations(&cmd_path, left);
		before_execve(right);
		if (g_data.redir_val)
		{
			execve(cmd_path, left->s_command->command, g_data.env);
			exit(1);
		}
		else
			exit(g_data.exit_num);
	}
}

void	before_execute_sub(t_syntax_tree *left, t_syntax_tree *right)
{
	if (g_data.pipe < g_data.cmd_count - 1)
		pipe(g_data.fd[g_data.pipe]);
	g_data.pids[g_data.cmd] = fork();
	if (g_data.pids[g_data.cmd] == -1)
		perror("Error on fork");
	if (g_data.pids[g_data.cmd] == 0)
	{
		signal(SIGQUIT, &sig_handler);
		child_process(left, right);
	}
	if (g_data.pipe < g_data.cmd_count - 1)
		main_process(g_data.fd[g_data.pipe]);
}

void	before_execute(t_syntax_tree *tree)
{
	t_syntax_tree	*left;
	t_syntax_tree	*right;

	g_data.cmd++;
	left = tree->left;
	right = tree->right;
	if (g_data.cmd_count == 1 && is_builtin(left->s_command->command[0]))
	{
		if (right)
			redirection(right);
		g_data.exit_num = which_builtin(left->s_command->command);
	}
	else
	{
		before_execute_sub(left, right);
	}
}
