#include	"get_next_line.h"

size_t	ft_strlen(char *buf)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
		i++;
	return (i);
}

char	*strjoin(char *s1, char *s2)
{
	char	*return_str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc (sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	return_str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = -1;
	j = 0;
	while (s1[++i])
		return_str[i] = s1[i];
	while (s2[j])
		return_str[i++] = s2[j++];
	return_str[i] = '\0';
	free (s1);
	return (return_str);
}

int	find_nl_char(char *buffer)
{
	int	i;

	i = -1;
	if (!buffer)
		return (0);
	while (buffer[++i])
		if (buffer[i] == '\n')
			return (1);
	return (0);
}

char	*get_new_line(char *buffer)
{
	char	*line;
	int		i;
	int		nl;

	nl = find_nl_char(buffer);
	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + nl + 1));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_new_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free (buffer);
	return (new_buffer);
}
