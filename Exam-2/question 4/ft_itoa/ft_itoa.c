#include <stdlib.h>
#include <stdio.h>

int ft_negative(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int ft_len(int nbr)
{
	int len = 0;

	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr /= 10;
	}
	return (len);
}
char *ft_itoa(int nbr)
{
    int len = ft_len(nbr);
    char *res = malloc(sizeof(char) * (len + 1));
	res[len] = '\0';

	if (nbr < 0)
		res[0] = '-';
	else if (nbr == 0)
		res[0] = '0';
    
	while (nbr != 0)
	{
		--len;
		res[len] = ft_negative(nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}

/*
int main(void)
{
	int d = INT_MIN;
	printf("%d = %s\n", d, ft_itoa(d));

	d = -13;
	printf("%d = %s\n", d, ft_itoa(d));

	d = 0;
	printf("%d = %s\n", d, ft_itoa(d));

	d = 5;
	printf("%d = %s\n", d, ft_itoa(d));

	d = INT_MAX;
	printf("%d = %s\n", d, ft_itoa(d));
}
*/
