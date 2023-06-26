#include <unistd.h>
#include <stdarg.h>

void ft_str_null(char *str, int *leng)
{
    if (str == NULL)
        str = "(null)";
    while (*str)
        *leng += write(1, str++, 1);
}

void hex_digit(long long int nbr, int base, int *leng)
{
    if (nbr < 0)
    {
        nbr *= -1;
        *leng += write(1, "-", 1);
    }
    if (nbr >= base)
        hex_digit((nbr / base), base, leng);
    *leng += write(1, &"0123456789abcdef"[nbr % base], 1);
}

int ft_printf(const char *str, ...)
{
    int leng = 0;

    va_list pointer;
    va_start(pointer, str);

    while (*str)
    {
        if ((*str == '%') && *(str + 1))
        {
            str++;
            if (*str == 's')
                ft_str_null(va_arg(pointer, char *), &leng);
            else if (*str == 'd')
                hex_digit((long long int)va_arg(pointer, int), 10, &leng);
            else if (*str == 'x')
                hex_digit((long long int)va_arg(pointer, unsigned int), 16, &leng);
        }
        else
            leng += write(1, str, 1);
        str++;
    }
    va_end(pointer);
    return (leng);
}

----------------------------------------------------------------------------------

// ----------------------   We can also write the printf as: -----------------------

/*
int ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int	i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}	
	return (i);
}


int	ft_putbase(unsigned int nbr, int base)
{
	int n = 0;
	int count = 0;
	char *base_set = "0123456789abcdef";
	
	n = nbr % base;
	if (nbr / base > 0)
		count += ft_putbase(nbr / base, base);
	count += ft_putchar(base_set[n]);
	return(count);
}

int	ft_putint(int nbr)
{
	int count = 0;

	if (nbr < 0)
	{	
		nbr *= -1;
		count += ft_putchar('-');
	}
	count += ft_putbase(nbr, 10);
	return(count);
}

int ft_printf(const char *str, ...)
{
	int i = 0;
	int count = 0;
	
	va_list args;
	va_start(args, str);
	
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if(str[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (str[i] == 'd')
				count += ft_putint(va_arg(args, int));
			else if (str[i] == 'x')
				count += ft_putbase(va_arg(args, unsigned int), 16);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return(count);
}
*/
