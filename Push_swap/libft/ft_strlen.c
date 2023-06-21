#include "libft.h"
//#include	<stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	dll;

	dll = 0;
	while (str[dll] != '\0')
		dll++;
	return (dll);
}
/*
int	main()
{
	printf("%zu",ft_strlen("agshdhsajk"));
}
*/
