#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] && s2[i])
        i++;
    return (s1[i] - s2[i]);
}

/*
int main()
{
    char k1[] = "abc";
    char k2[] = "def";
    printf("%d\n", ft_strcmp(k1, k2));
}
*/
