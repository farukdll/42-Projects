#include <stdio.h>

char *ft_strcpy(char *s1, char *s2)
{
    int i = 0;

    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

/*
int main()
{
    char k1[] = "s1 value = anything";
    char k2[] = "copied part = k2";

    ft_strcpy(k1, k2);
    printf("%s\n", k1);
}
*/
