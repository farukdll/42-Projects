#include <unistd.h>
#include <signal.h>

void	ft_bit_editing(int x)
{
	static int				bit = 7;
	static unsigned char	set = 0;

	set = set + (x << bit);
	if (bit == 0)
	{
		write(1, &set, 1);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

void	ft_signal_catch(int x)
{
	if (x == SIGUSR1)
		ft_bit_editing(1);
	else
		ft_bit_editing(0);
}

void	ft_putnbr(int n)
{
	if (n > 10)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, ft_signal_catch);
	signal(SIGUSR2, ft_signal_catch);
	while (1)
		pause();
}
