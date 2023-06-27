#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **ft_split(char *str)
{
    char **split = (char **)malloc(1000);
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        split[k] = malloc(1000);
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '\n')
        {
            split[k][j] = str[i];
            i++;
            j++;
        }
        split[k][j] = '\0';
        if (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\0')
            k++;
        j = 0;
    }
    split[k] = NULL;
    return (split);
}
/*
int main()
{
    char *a = "    leonardoo   42 split     ";
    char **res = ft_split(a);
    int index = 0;

    while (res[index])
    {
        printf("%s\n", res[index]);
        index++;
    }
}
*/
//
//
//
//          You can understand in more detail in 3 functions below.
//
//          Good work and good luck...
//
//
//
/*
char **ft_split(char *str)
{
    char **split;
    int len = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            if (str[i + 1] && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n'))
                len++;
            else if (str[i + 1] == '\0')
                len++;
        }
        i++;
    }
    split = (char **)malloc(sizeof(char *) * (len + 1));

    i = 0;
    int k = 0;
    len = 0;

    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            len++;
            if (str[i + 1] == '\0')
            {
                split[k] = (char *)malloc(sizeof(char) * (len + 1));
                k++;
            }
        }
        else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            if (i > 0 && str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\n')
            {
                split[k] = (char *)malloc(sizeof(char) * (len + 1));
                k++;
                len = 0;
            }
        }
        i++;
    }
    split[k] = NULL;
    i = 0;
    k = 0;
    int j = 0;

    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            split[k][j] = str[i];
            j++;
            if (str[i + 1] && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n'))
            {
                split[k][j] = '\0';
                k++;
                j = 0;
            }
            else if (str[i + 1] == '\0')
            {
                split[k][j] = '\0';

                k++;
                j = 0;
            }
        }
        i++;
    }
    return split;
}
*/
/*
int main()
{
    char *str;

    str = malloc(sizeof(char) * 74);

    strcpy(str,  "    leonardoo   42 split     ");

    char **abc = ft_split(str);
    int i = 0;

    while (i < 5)
    {
        printf("%s\n", abc[i]);
        i++;
    }
}
*/

