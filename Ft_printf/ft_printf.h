#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printchar(char c);
int	format(char c, va_list arg);
int	ft_printf(const char *str, ...);
int	ft_printstr(const char *str);
int	ft_printpointer(unsigned long int n);
int	ft_printnbr(int nb);
int	ft_printunbr(unsigned int nb);
int	ft_printhex(char c, unsigned int sayi);

#endif
