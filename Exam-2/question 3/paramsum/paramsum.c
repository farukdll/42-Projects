#include <unistd.h>

void ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}

int main(int ac, char **av)
{
    (void)av;

    if (ac > 1)
    {
        ft_putnbr(ac - 1);
        write(1, "\n", 1);
    }
    else
    {
        write(1, "0", 1);
        write(1, "\n", 1);
    }
}
