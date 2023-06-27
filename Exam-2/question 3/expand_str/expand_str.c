#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int k = 0;

    if (ac == 2)
    {
        i = 0;
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        while (av[1][i])
        {
            if (av[1][i] == ' ' || av[1][i] == '\t')
                k = 1;
            if (!(av[1][i] == ' ' || av[1][i] == '\t'))  // if (av[1][i] != ' ' && av[1][i] != '\t')  -->  It can also be written like this
            {
                if (k)
                    write(1, "   ", 3);
                k = 0;
                write(1, &av[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}
