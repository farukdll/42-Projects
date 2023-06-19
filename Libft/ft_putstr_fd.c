#include	"libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!fd || !s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*
int	main()
{
	int	fd1 = open("foo.txt", O_CREAT | O_WRONLY, 0644);
	ft_putstr_fd("Regular Show", fd1);
}
*/
