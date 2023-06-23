#include "minishell_builtins.h"

void	command_cd_change_pwd(char ***exp, char ***env)
{
	int		env_pwd_line;
	char	*cwd;
	char	*new_pwd;
	char	*env_pwd;
	char	*old_pwd;

	cwd = getcwd(NULL, 0);
	env_pwd_line = find_line_char_matrix(*env, "PWD=", ENV_LIST, 4);
	if (env_pwd_line == -1)
		command_export(exp, env, "OLDPWD=");
	else
	{
		env_pwd = get_var_data(env[0][env_pwd_line]);
		old_pwd = ft_strjoin("OLDPWD=", env_pwd);
		command_export(exp, env, old_pwd);
		free_two_str(&env_pwd, &old_pwd);
	}
	new_pwd = ft_strjoin("PWD=", cwd);
	command_export(exp, env, new_pwd);
	free_two_str(&new_pwd, &cwd);
}

int	improved_chdir(char *go_dir, char *incoming_dir)
{
	if (!incoming_dir)
		incoming_dir = go_dir;
	if (chdir(go_dir) == -1)
	{
		printf("cd: %s: No such file or directory\n", incoming_dir);
		return (1);
	}
	return (0);
}

int	command_cd_swap_pwd(char ***exp, char ***env)
{
	int		old_pwd_index;
	char	*var_data;
	char	*cwd;
	char	*actual_data;

	old_pwd_index = find_line_char_matrix(*env, "OLDPWD=", ENV_LIST, 7);
	if (old_pwd_index == -1)
		return (1);
	else
	{
		var_data = env[0][old_pwd_index];
		actual_data = get_var_data(var_data);
		if (improved_chdir(actual_data, NULL) == 1)
			return (1);
		printf("%s\n", actual_data);
		cwd = getcwd(NULL, 0);
		command_unset_env(exp, "OLDPWD=");
	}
	return (0);
}

int	command_cd_tilde(char *dir, char ***env)
{
	int		home_index;
	char	*home_data;
	char	*go_dir;
	char	*nul;

	nul = NULL;
	home_index = find_line_char_matrix(*env, "HOME=", ENV_LIST, 5);
	if (home_index == -1)
		return (1);
	home_data = get_var_data(env[0][home_index]);
	if (ft_strncmp(dir, "~", 2) == 0)
	{
		if (improved_chdir(home_data, dir) == 1)
			return (free_two_str(&home_data, &nul) * -1);
	}
	else if (ft_strncmp(dir, "~/", 2) == 0)
	{
		go_dir = ft_strjoin(home_data, dir + 1);
		if (improved_chdir(go_dir, dir) == 1)
			return (free_two_str(&home_data, &go_dir) * -1);
	}
	else
		printf("cd: %s: No such file or directory\n", dir);
	free(home_data);
	return (0);
}

int	command_cd(char *dir, char ***exp, char ***env)
{
	int	exit;

	if (!dir)
	{
		if (command_cd_tilde("~", env) == 1)
		{
			printf("cd: HOME not set\n");
			exit = 1;
		}
		else
			exit = 0;
	}
	else if (ft_strncmp(dir, "~", 1) == 0)
		exit = command_cd_tilde(dir, env);
	else if (ft_strncmp(dir, "-", 1) == 0)
		exit = command_cd_swap_pwd(exp, env);
	else
		exit = improved_chdir(dir, NULL);
	if (exit == 0)
		command_cd_change_pwd(exp, env);
	return (exit);
}
