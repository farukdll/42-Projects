#include	"libft.h"
//#include	<stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	dll;

	dll = 0;
	while (s[dll] != '\0')
		dll++;
	return (dll);
}
/*
int	main()
{
	printf("%zu",ft_strlen("agshdhsajk"));
}
*/
