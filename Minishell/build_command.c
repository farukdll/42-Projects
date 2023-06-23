#include "minishell.h"

void	build_command(t_command	**command, char **cmd)
{
	char	**quote_cleaned_cmd;
	char	**splited_cmd;
	char	*tmp;

	if (!*cmd || ft_space_cntrl(*cmd))
		*command = NULL;
	else
	{
		tmp = ft_str_clearspace(*cmd);
		splited_cmd = parser_split_process(tmp);
		quote_cleaned_cmd = ft_strdup_multi(splited_cmd);
		parser_array_clearquotes(quote_cleaned_cmd);
		*command = new_s_command(quote_cleaned_cmd);
		ft_double_free(splited_cmd, parser_array_getsize(splited_cmd));
	}
}

t_syntax_tree	*build_exec(char	*arg_command)
{
	char			*tmp_command;
	t_syntax_tree	*exec;
	t_command		*command;
	t_redirection	*redir;

	redir = NULL;
	command = NULL;
	tmp_command = ft_strdup(arg_command);
	exec = new_s_syntax_tree(EXEC);
	build_redirection(&redir, &tmp_command);
	build_command(&command, &tmp_command);
	if (redir)
	{
		exec->right = new_s_syntax_tree(REDIR);
		exec->right->s_redir = redir;
		exec->right->prev = exec;
	}
	if (command)
	{
		exec->left = new_s_syntax_tree(COMMAND);
		exec->left->s_command = command;
		exec->left->prev = exec;
	}
	free(tmp_command);
	return (exec);
}
