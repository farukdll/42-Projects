#include "minishell.h"

t_vars	g_data;

void	all_mallocs(void)
{
	int	i;

	i = -1;
	if (g_data.count_in)
		g_data.infiles = malloc(g_data.count_in * sizeof(int));
	if (g_data.count_out)
		g_data.outfiles = malloc(g_data.count_out * sizeof(int));
	if (g_data.count_her)
	{
		g_data.heredoc = (int **)malloc(g_data.count_her * sizeof(int *));
		while (++i < g_data.count_her)
			g_data.heredoc[i] = malloc(sizeof(int) * 2);
	}
	i = -1;
	if (g_data.cmd_count)
		g_data.pids = malloc(sizeof(pid_t) * g_data.cmd_count);
}

void	assign_defaults(t_syntax_tree *tree, t_arg args)
{
	g_data.exit_num = 0;
	g_data.count_in = 0;
	g_data.count_out = 0;
	g_data.count_her = 0;
	g_data.ref_her = -1;
	g_data.interrupt = 1;
	g_data.redir_val = 1;
	g_data.cmd = -1;
	g_data.pipe = 0;
	g_data.cmd_count = args.cmd_count;
	all_redirs(tree);
	all_mallocs();
}

void	ft_interrput(t_syntax_tree **tree, t_arg *arg, \
	char *str, int ac)
{
	(void)ac;
	assign_defaults(tree[0], *arg);
	all_heredocs(tree[0]);
	free(str);
	if (g_data.interrupt)
	{
		if (tree[0]->type == EXEC || tree[0]->type == PIPE)
			executer(tree[0]);
		dup2(g_data.dup_in, 0);
		dup2(g_data.dup_out, 1);
		if (arg)
		{
			del_list(tree);
			ft_double_free(arg->arg_commands, \
			parser_array_getsize(arg->arg_commands));
			ft_freeall(arg);
		}
	}
}

int	check_str(char *str, t_arg *arg)
{
	if (!*str || arg == NULL || !ft_strlen(arg->arg_commands[0]))
	{
		free(str);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char			*str;
	t_syntax_tree	*tree;
	t_arg			*arg;

	(void)av;
	g_data.env = ft_strdup_multi(envp);
	g_data.export = set_export_quote(envp);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &ctrl_c);
		str = readline("$ >_ ");
		if (!str)
			ctrl_d();
		g_data.dup_in = dup(0);
		g_data.dup_out = dup(1);
		arg = parser_process(str, &g_data);
		if (check_str(str, arg) == 0)
			continue ;
		add_history(str);
		tree = new_tree(arg);
		if (g_data.syntax_err == 1)
			continue ;
		ft_interrput(&tree, arg, str, ac);
	}
}
