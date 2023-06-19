#include	"libft.h"
//#include	<stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s2 && *s1 == *s2 && n-- - 1)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
int	main()
{
	printf("%d", ft_strncmp("lio", "leo", 3));
}
*/
