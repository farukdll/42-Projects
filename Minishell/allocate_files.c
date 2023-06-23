#include "minishell.h"

void	count_redirs(t_syntax_tree *tree_redir)
{
	t_redirection	*new;
	char			*redir;

	new = tree_redir->s_redir;
	while (new)
	{
		redir = new->redir;
		if (!ft_strncmp(redir, "<", 2))
		{
			new->in_index = g_data.count_in;
			g_data.count_in += 1;
		}
		else if (!ft_strncmp(redir, ">>", 3) || !ft_strncmp(redir, ">", 2))
		{
			new->out_index = g_data.count_out;
			g_data.count_out += 1;
		}
		else if (!ft_strncmp(redir, "<<", 3))
		{
			new->her_index = g_data.count_her;
			g_data.count_her += 1;
		}
		new = new->next;
	}
}

void	all_redirs(t_syntax_tree *tree)
{
	if (tree->type == EXEC)
	{
		if (tree->right)
			count_redirs(tree->right);
	}
	else
	{
		if (tree->left->right)
			count_redirs(tree->left->right);
		if (tree->right->type == PIPE)
			all_redirs(tree->right);
		else
		{
			if (tree->right->right)
				count_redirs(tree->right->right);
		}
	}
}
