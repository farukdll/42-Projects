#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int start;
    int end;
    int flag = 0;
    int all_space = 0;

    if (ac > 1)
    {
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        start = i;
        while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
            i++;
        end = i;
        while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
            i++;
        if (av[1][i] == '\0')
            all_space = 1;
        while (av[1][i])
        {
            if (av[1][i] == ' ' || av[1][i] == '\t')
                flag = 1;
            write(1, &av[1][i], 1);
            if (flag == 1)
            {
                i++;
                while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
                    i++;
                i--;
                flag = 0;
            }
            i++;
        }
        if (all_space == 0)
            write(1, " ", 1);
        while(start < end)
        {
            write(1, &av[1][start], 1);
            start++;
        }
    }
    write(1, "\n", 1);
}

