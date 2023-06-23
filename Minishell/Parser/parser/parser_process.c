#include "../../minishell.h"

void	*parser_process_init(char *str, t_parser *p)
{
	if (parser_check_error(str) == 0)
		return (NULL);
	p->tmp = malloc(sizeof(char **));
	p->ret = malloc(sizeof(char **));
	p->arg = malloc(sizeof(t_arg));
	p->tmp[0] = ft_strtrim(str, " ");
	return ((void *)1);
}

t_arg	*parser_process(char *str, t_vars *g_data)
{
	t_parser	p;

	if (parser_process_init(str, &p) == 0)
		return (NULL);
	if (p.tmp[0] == NULL)
		return ((void *)(uintptr_t)ft_double_free(p.tmp, 1));
	p.ret[0] = ft_str_clearspace(p.tmp[0]);
	if (p.ret[0] == NULL)
		return ((void *)(uintptr_t)ft_double_free(p.tmp, 1));
	ft_double_free(p.tmp, 1);
	p.tmp = parser_cmd_split(p.ret[0], '|');
	if (p.tmp == NULL)
		return ((void *)(uintptr_t)ft_double_free(p.ret, 1));
	ft_double_free(p.ret, 1);
	p.ret = parser_array_trim(p.tmp);
	if (p.ret == NULL)
		return ((void *)(uintptr_t) \
			ft_double_free(p.tmp, parser_array_getsize(p.tmp)));
	ft_double_free(p.tmp, parser_array_getsize(p.tmp));
	p.tmp = interpreter_array_format(p.ret, g_data);
	if (p.tmp == NULL)
		ft_double_free(p.ret, parser_array_getsize(p.ret));
	p.arg->arg_commands = p.tmp;
	p.arg->cmd_count = parser_array_getsize(p.ret);
	return (p.arg);
}
