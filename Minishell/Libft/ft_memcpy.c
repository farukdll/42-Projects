#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t	i;

	if (dest == src || !num)
		return (dest);
	i = 0;
	while (i < num)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}
