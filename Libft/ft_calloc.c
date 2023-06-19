#include	"libft.h"
//#include	<stdio.h>

void	*ft_calloc(size_t size, size_t count)
{
	void	*num;

	num = malloc(count * size);
	if (num == NULL)
		return (num);
	ft_bzero(num, size * count);
	return (num);
}
/*
int	main()
{
	int	*a = ft_calloc(10, sizeof(int));
	printf("%d", *a);
}
*/
