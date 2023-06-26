#include <unistd.h>
#include <stdlib.h>
//#include "get_next_line.h"

#ifndef BUFFER_SIZE       // Do not forget to transfer these 3 lines to the .h file, as the exam asks for a .h file.
# define BUFFER_SIZE 42
#endif


int ft_strlen(char *str)
{
    int idx;
    
    idx = 0;
    if (!str)
        return (0);
    while (str[idx])
        idx++;
    return (idx);
}

char *ft_strchr(char *str, char c)
{
    int idx;

    idx = 0;
    if (!str)
        return (0);
    if (c == '\0')
        return ((char *)&str[ft_strlen(str)]);
    while (str[idx])
    {
        if (str[idx] == c)
            return ((char *)&str[idx]);
        idx++;
    }
    return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
    int idx;
    int c;
    char *str;

    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    idx = 0;
    c = 0;
    while (s1[c])
        str[idx++] = s1[c++];
    c = 0;
    while (s2[c])
        str[idx++] = s2[c++];
    str[idx] = '\0';
    free(s1);
    return (str);
}

char	*get_line(char *str)
{
	int		idx;
	char	*line;

	idx = 0;
	if (!str[idx])
		return (NULL);
	while (str[idx] != '\n' && str[idx] != '\0')
		idx++;
	line = (char *)malloc(sizeof(char) * (idx + 2));
	if (!line)
		return (NULL);
	idx = 0;
	while (str[idx] && str[idx] != '\n')
	{
		line[idx] = str[idx];
		idx++;
	}
	if (str[idx] == '\n')
	{
		line[idx] = str[idx];
		idx++;
	}
	line[idx] = '\0';
	return (line);
}

char	*get_remain(char *str)
{
	int		i;
	int		s;
	int		_lenstr;
	char	*remain;

	_lenstr = ft_strlen(str);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
        free(str);
		return (NULL);
	}
	remain = (char *)malloc(sizeof(char) * (_lenstr - i + 1));
	if (!remain)
		return (NULL);
	i++;
	s = 0;
	while (str[i] != '\0')
		remain[s++] = str[i++];
	remain[s] = '\0';
	free(str);
	return (remain);
}

char	*ft_update(int fd, char *saved)
{
	int		read_bytes;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(saved, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(saved);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		saved = ft_strjoin(saved, buff);
	}
	free(buff);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, str, 0) < 0)
		return (NULL);
	str = ft_update(fd, str);
	line = get_line(str);
	str = get_remain(str);
	return (line);
}
