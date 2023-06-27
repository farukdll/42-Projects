#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src)
{
    int i = 0;
    char *dest;

    while (src[i])
        i++;
    dest = malloc(sizeof(char) * (i + 1));
    if (dest == NULL)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return (dest);
}
/*
int main()
{
    printf("%s\n", ft_strdup("good"));
}
*/
