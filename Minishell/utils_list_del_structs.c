#include "minishell.h"

void	del_s_command(t_command *del)
{
	int	i;

	i = -1;
	if (!del)
		return ;
	while (del->command[++i])
		ft_bzero(del->command[i], ft_strlen(del->command[i]));
	i = -1;
	while (del->command[++i])
		free(del->command[i]);
	if (del->command)
		free(del->command);
	free(del);
}

void	del_s_redirection(t_redirection *del)
{
	t_redirection	*iter;

	if (!del)
		return ;
	while (del)
	{
		iter = del;
		del = del->next;
		ft_bzero(iter->redir, ft_strlen(iter->redir));
		ft_bzero(iter->args, ft_strlen(iter->args));
		free(iter->redir);
		free(iter->args);
		free(iter);
	}
	free(del);
}

void	del_s_syntax_tree(t_syntax_tree *del)
{
	del_s_command(del->s_command);
	del_s_redirection(del->s_redir);
	free(del);
}
