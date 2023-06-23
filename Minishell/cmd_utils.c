#include "minishell.h"

int	command_w_path(char **command)
{
	char	*command_path;
	int		start_idx;

	command_path = ft_strdup(command[0]);
	free(command[0]);
	if (access(command_path, X_OK) == -1)
	{
		g_data.exit_num = 127;
		write(2, command_path, ft_strlen(command_path));
		write(2, ": No such file or directory\n", 29);
		free(command_path);
		return (0);
	}
	start_idx = ft_strrchr(command_path, '/') - command_path;
	command[0] = ft_substr(command_path, start_idx + 1, \
		ft_strlen(command_path) - start_idx);
	return (1);
}

char	*get_path(char **env)
{
	int		line;
	char	*path;

	line = -1;
	while (env[++line])
	{
		if (!ft_strncmp(env[line], "PATH=", 5))
			break ;
	}
	if (!env[line])
		return (NULL);
	path = ft_substr(env[line], 5, ft_strlen(env[line]) - 5);
	return (path);
}

char	*get_cmd(char *cmd, char *path)
{
	char	*command;
	char	**path_list;
	char	*temp_command;
	int		i;

	i = -1;
	path_list = ft_split(path, ':');
	while (path_list[++i])
	{
		temp_command = ft_strjoin(path_list[i], "/");
		command = ft_strjoin(temp_command, cmd);
		free(temp_command);
		if ((access(command, X_OK) == 0))
		{
			free_char_matrix(&path_list);
			return (command);
		}
		free(command);
	}
	free_char_matrix(&path_list);
	return (NULL);
}
