#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int k = 0;

    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        k = k * 10 + str[i] - '0';
        str++;
    }
    return (k);
}

void ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 1;
        int k;

        k = ft_atoi(av[1]);
        while (i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(k);
            write(1, " = ", 3);
            ft_putnbr(i * k);
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}
