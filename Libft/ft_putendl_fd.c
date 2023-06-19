#include	"libft.h"
//#include	<fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!fd || !s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &"\n", 1);
}
/*
int	main()
{
	int	fd1 = open("test.txt", O_CREAT | O_WRONLY, 0644);
	ft_putendl_fd("Leonardo", fd1);
}
*/
