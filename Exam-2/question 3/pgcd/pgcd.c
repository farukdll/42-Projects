#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int nb_1;
    int nb_2;

    if (ac == 3)
    {
        nb_1 = atoi(av[1]);
        nb_2 = atoi(av[2]);
        while ((nb_1 > 0) && (nb_2 > 0))
        {
            if (nb_1 > nb_2)
                nb_1 -= nb_2;
            else
                nb_2 -= nb_1;
        }
        printf("%d", nb_1);
    }
    printf("\n");
}
