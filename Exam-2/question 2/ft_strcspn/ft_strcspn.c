#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int r;

    while (s[i])
    {
        r = 0;
        while (reject[r])
        {
            if (s[i] == reject[r])
                return (i);
            r++;
        }
        i++;
    }
    return (i);
}
/*
int main(void)
{
    printf("%lu\n", ft_strcspn("test", "es"));
    printf("%lu\n", strcspn("test", "es"));
    printf("%lu\n", ft_strcspn("test", "f"));
    printf("%lu\n", strcspn("test", "f"));
}
*/
