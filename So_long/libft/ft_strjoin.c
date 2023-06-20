#include	"libft.h"
//#include	<stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr;

	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ptr = str;
	while (*s1)
		*(str++) = *(s1++);
	while (*s2)
		*(str++) = *(s2++);
	*str = '\0';
	return (ptr);
}
/*
int main()
{
	char a[] = "Regular";
	char b[] = "Show";
    printf("\n%s\n\n", ft_strjoin(a,b));
}
*/
