#include	"get_next_line.h"

char	*get_line(int fd, char *buffer)
{
	char	*buff;
	int		rd_byte;

	rd_byte = 1;
	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!find_nl_char(buffer) && rd_byte != 0)
	{
		rd_byte = read (fd, buff, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			free (buffer);
			free (buff);
			return (NULL);
		}
		buff[rd_byte] = '\0';
		buffer = strjoin(buffer, buff);
	}
	free (buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = get_line(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = get_new_line(buffer);
	buffer = get_new_buffer(buffer);
	return (line);
}
