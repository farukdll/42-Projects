#include <stdio.h>
#include <stdlib.h>

char *ft_strrev(char *str)
{
    int i = -1;
    int len = 0;
    char tmp;

    while (str[len])
        len++;
    while (++i < --len)
    {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
    }
    return (str);
}
/*
int main()
{
    char res[] = "good";
    printf("%s\n", ft_strrev(res));
}
*/
