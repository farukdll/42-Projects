#include	"libft.h"
//#include	<fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main()
{
	int	fd1 = open("test.txt", O_CREAT | O_WRONLY, 0644);
	ft_putchar_fd('a', fd1);
}
*/
