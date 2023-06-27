#include <stdio.h>

int max(int *tab, unsigned int len)
{
	unsigned int i = 0;
	int	max;
    
	if (len == i)
		return (0);
    
	max = tab[0];
	while (len > 0 && i < len)
	{
		if (tab[i] >= max)
			max = tab[i];
		i++;
	}
	return (max);
}
/*
int main()
{
    int tab[] = {-42, 4000000, -5, -20, 2, -200, 99};
    printf("max : %d\n", max(tab, 7));
}
*/
