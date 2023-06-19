#include	"libft.h"
//#include	<stdio.h>
//#include	<string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;

	a = 0;
	while (*dst && a < dstsize)
	{
		++dst;
		++a;
	}
	b = ft_strlcpy(dst, src, dstsize - a);
	return (b + a);
}
/*
int	main()
{
	char src_1[] = "Kaplumbağalar";
	char dst_2[20] = "Ninja";
	char dst_1[20] = "Ninja";
	printf("\nÖnce : %s\n", dst_1);
	printf("%lu\n", ft_strlcat(dst_1, src_1, sizeof(dst_1)));
	printf("\nSonra : %s\n", dst_1);
	printf("%lu\n", strlcat(dst_2, src_1, sizeof(dst_2)));
}
*/
