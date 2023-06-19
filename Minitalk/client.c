#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	number;

	number = 0;
	while (*str)
	{
		number = (10 * number) + (*str - 48);
		str++;
	}
	return (number);
}

void	ft_bit_and_shift(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Warning!, you have to enter 3 arguments.\n", 41);
		return (0);
	}
	ft_bit_and_shift(ft_atoi(argv[1]), argv[2]);
	ft_bit_and_shift(ft_atoi(argv[1]), "\n");
}
