#include	"ft_printf.h"

int	ft_printunbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb < 10)
		len += ft_printchar(nb + '0');
	else
	{
		len += ft_printunbr(nb / 10);
		len += ft_printunbr(nb % 10);
	}
	return (len);
}

int	ft_printhex(char c, unsigned int sayi)
{
	int	len;

	len = 0;
	if (sayi == 0)
		return (ft_printchar('0'));
	if (sayi >= 16)
		len += ft_printhex(c, sayi / 16);
	if (c == 'x')
		len += ft_printchar("0123456789abcdef"[sayi % 16]);
	else
		len += ft_printchar("0123456789ABCDEF"[sayi % 16]);
	return (len);
}

int	format(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_printchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_printstr(va_arg(arg, char *));
	else if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_printpointer(va_arg(arg, unsigned long int));
	}
	else if (c == 'd' || c == 'i')
		len += ft_printnbr(va_arg(arg, int));
	else if (c == 'u')
		len += ft_printunbr(va_arg(arg, unsigned int));
	else if (c == '%')
		len += write(1, "%", 1);
	else if (c == 'x' || c == 'X')
		len += ft_printhex(c, va_arg(arg, unsigned int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		print_number;
	int		i;
	va_list	arg;

	i = 0;
	print_number = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_number += format(str[++i], arg);
			i++;
		}
		else
			print_number += ft_printchar(str[i++]);
	}
	return (print_number);
}
