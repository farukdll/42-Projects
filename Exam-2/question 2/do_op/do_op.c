#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int nb1 = 0;
	int nb2 = 0;
	int k = 0;

	if (ac == 4)
	{
		nb1 = atoi(av[1]);
		nb2 = atoi(av[3]);
		if (av[2][0] == '+')
			k = nb1 + nb2;
		if (av[2][0] == '-')
			k = nb1 - nb2;
		if (av[2][0] == '*')
			k = nb1 * nb2;
		if (av[2][0] == '/')
			k = nb1 / nb2;
		if (av[2][0] == '%')
			k = nb1 % nb2;
		printf("%d\n", k);
	}
	else
		printf("\n");
}
