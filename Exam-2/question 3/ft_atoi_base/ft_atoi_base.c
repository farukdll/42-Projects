#include <stdio.h>

int ft_check(char *str, char c)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return i;
        i++;
    }
    return 0;
}
int ft_atoi_base(const char *str, int str_base)
{
    char *s = "0123456789abcdef";
    char *s1 = "0123456789ABCDEF";
    int i = 0;
    int c = 0;
    int sign = 1;
    int tmp;

    if (str[i] == '-')
    {
        sign *= -1;
        i++;
    }
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            tmp = ft_check(s, str[i]);
            if (tmp == 0)
                break;
            else
            {
                c *= str_base;
                c += (sign * tmp);
            }
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            tmp = ft_check(s1, str[i]);
            if (tmp == 0)
                break;
            else
            {
                c *= str_base;
                c += (sign * tmp);
            }
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            tmp = ft_check(s, str[i]);
            if (tmp == 0)
                break;
            else
            {
                c *= str_base;
                c += (sign * tmp);
            }
        }
        else
            break;
        i++;
    }
    return (c);
}
/*
int main()
{
    printf("%d", ft_atoi_base("f", 16));
}
*/
