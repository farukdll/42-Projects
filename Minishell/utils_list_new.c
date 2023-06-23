#include "minishell.h"

t_syntax_tree	*new_s_syntax_tree(int type)
{
	t_syntax_tree	*new;

	new = (t_syntax_tree *)malloc(sizeof(t_syntax_tree));
	if (!new)
		perror("Malloc Error");
	new->s_command = NULL;
	new->s_redir = NULL;
	new->left = NULL;
	new->right = NULL;
	new->prev = NULL;
	new->type = type;
	return (new);
}

t_command	*new_s_command(char **command)
{
	t_command	*new;

	new = (t_command *)malloc(sizeof(t_command));
	if (!new)
		perror("Malloc Error");
	new->command = command;
	return (new);
}

t_redirection	*new_s_redirection(char *redir, char *args)
{
	t_redirection	*new;

	new = (t_redirection *)malloc(sizeof(t_redirection));
	if (!new)
		perror("Malloc Error");
	new->redir = redir;
	new->args = args;
	new->next = NULL;
	new->her_index = -1;
	new->in_index = -1;
	new->out_index = -1;
	return (new);
}
