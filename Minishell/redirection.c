#include "minishell.h"

int	last_infile(t_redirection *new, char *redir)
{
	while (new)
	{
		redir = new->redir;
		if (!ft_strcmp(redir, "<"))
		{
			g_data.infiles[new->in_index] = open(new->args, O_RDONLY);
			if (g_data.infiles[new->in_index] == -1)
			{
				perror("Opening file error");
				g_data.exit_num = 1;
				return (0);
			}
			dup_infile(new->in_index);
		}
		else if (!ft_strcmp(redir, "<<"))
		{
			if (dup2(g_data.heredoc[new->her_index][0], 0) == -1)
				perror("Error on dup2");
			if (close(g_data.heredoc[new->her_index][0]))
				perror("Error on closing infile");
		}
		new = new->next;
	}
	return (1);
}

int	last_outfile_sub(t_redirection *new)
{
	g_data.outfiles[new->out_index] = open(new->args, \
		O_CREAT | O_RDWR | O_APPEND, 0777);
	if (g_data.outfiles[new->out_index] == -1)
	{
		perror("Opening file error");
		g_data.exit_num = 258;
		return (0);
	}
	dup_outfile(new->out_index);
	return (1);
}

int	last_outfile(t_redirection *new, char *redir)
{
	while (new)
	{
		redir = new->redir;
		if (!ft_strcmp(redir, ">"))
		{
			g_data.outfiles[new->out_index] = open(new->args,
					O_CREAT | O_TRUNC | O_RDWR, 0777);
			if (g_data.outfiles[new->out_index] == -1)
			{
				perror("Opening file error");
				g_data.exit_num = 258;
				return (0);
			}		
			dup_outfile(new->out_index);
		}
		else if (!ft_strcmp(redir, ">>"))
		{
			if (last_outfile_sub(new) == 0)
				return (0);
		}
		new = new->next;
	}
	return (1);
}

int	redirection(t_syntax_tree *tree)
{
	char			*redir;
	t_redirection	*new;
	int				out_error;
	int				in_error;

	new = tree->s_redir;
	redir = NULL;
	out_error = last_outfile(new, redir);
	new = tree->s_redir;
	in_error = last_infile(new, redir);
	if (!out_error || !in_error)
		return (0);
	return (1);
}
