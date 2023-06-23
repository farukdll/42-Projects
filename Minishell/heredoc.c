#include "minishell.h"

int	after_readline(char *str, char *arg)
{
	str = readline("heredoc> ");
	if (!str)
		ctrl_d();
	if (!ft_strcmp(str, arg))
	{
		free(str);
		write(g_data.heredoc[g_data.ref_her][1], str, ft_strlen(str));
		write(g_data.heredoc[g_data.ref_her][1], "\n", 1);
		return (0);
	}
	free(str);
	return (1);
}

void	ft_heredoc(char *arg)
{
	pid_t	pid1;

	if (!g_data.exit_num)
	{
		pipe(g_data.heredoc[++g_data.ref_her]);
		pid1 = fork();
		if (pid1 == 0)
		{
			close(g_data.heredoc[g_data.ref_her][0]);
			signal(SIGINT, &sig_handler_heredoc);
			while (1)
			{
				if (!after_readline(NULL, arg))
					break ;
			}
			exit(0);
		}
		close(g_data.heredoc[g_data.ref_her][1]);
		waitpid(pid1, &g_data.exit_num, 0);
		if (WIFEXITED(g_data.exit_num))
			g_data.exit_num /= 256;
		if (g_data.exit_num == 1)
			g_data.interrupt = 0;
	}
}

void	isheredoc(t_syntax_tree *tree)
{
	t_redirection	*new;
	char			*redir;

	new = tree->s_redir;
	while (new)
	{
		redir = new->redir;
		if (!ft_strcmp(redir, "<<"))
			ft_heredoc(new->args);
		new = new->next;
	}
}

void	all_heredocs(t_syntax_tree *tree)
{
	if (tree->type == EXEC)
	{
		if (tree->right)
			isheredoc(tree->right);
	}
	else
	{
		if (tree->left->right)
			isheredoc(tree->left->right);
		if (tree->right->type == PIPE)
			all_heredocs(tree->right);
		else
		{
			if (tree->right->right)
				isheredoc(tree->right->right);
		}
	}
}
