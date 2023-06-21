#include "libft.h"
//#include    <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
	{
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
/*
int	main()
{
	char src_1[] = "leonardo";
	char dst_1[] = "ninjakaplumbağalar";
	printf("%s\n",ft_memmove(dst_1, src_1, 3));
}
*/
