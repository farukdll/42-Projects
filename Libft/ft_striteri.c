#include	"libft.h"
//#include	<stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}	
}
/*
void	f(unsigned int x, char *str)
{
	*str -= 32;
	printf("%s\n", str);
}

int main()
{
	char str[] = "regularshow";
	ft_striteri(str, f);
	printf("%s\n", str);
}
*/
