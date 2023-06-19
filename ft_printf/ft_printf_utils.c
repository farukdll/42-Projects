#include	"ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(const char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[len])
		write(1, &str[len++], 1);
	return (len);
}

int	ft_printpointer(unsigned long int n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_printpointer(n / 16);
	len += ft_printchar("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_printnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == INT_MIN)
	{
		len += ft_printstr("-2");
		nb = 147483648;
	}
	if (nb < 0)
	{
		len += ft_printchar('-');
		nb = nb * -1;
	}
	if (nb >= 0 && nb < 10)
		len += ft_printchar(nb + '0');
	else
	{
	len += ft_printnbr(nb / 10);
	len += ft_printnbr(nb % 10);
	}
	return (len);
}
