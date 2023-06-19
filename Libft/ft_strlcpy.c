#include	"libft.h"
//#include	<stdio.h>
//#include	<string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main()
{
	char src_1[] = "leonardo";
	char dst_1[] = "ninjakaplumbağalar";
	printf("%zu\n",ft_strlcpy(dst_1, src_1, 3));
	printf("%s", dst_1);
	return (0);
}
*/
