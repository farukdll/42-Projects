#include	"libft.h"
//#include	<fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		num = n + 48;
		write(fd, &num, 1);
	}
	while (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
		return ;
	}
}
/*
int	main()
{
	int	fd1 = open("test.txt", O_CREAT | O_RDWR, 0644);
	ft_putnbr_fd(-2147483648, fd1);
}
*/
