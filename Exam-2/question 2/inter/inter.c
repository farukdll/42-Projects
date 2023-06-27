#include <unistd.h>

int main(int ac, char **av)
{
    int k = 0;
    int s_1 = 0;
    int s_2 = 0;
    char *s1;
    char *s2;

    if (ac == 3)
    {
        s1 = av[1];
        s2 = av[2];
        while (s1[s_1])
        {
            s_2 = 0;
            while (s2[s_2])
            {
                if (s1[s_1] == s2[s_2])
                {
                    k = 0;
                    while (s1[s_1] != s1[k])
                        k++;
                    if (s_1 == k)
                    {
                        k = 0;
                        while (s2[s_2] != s2[k])
                            k++;
                        if (s_2 == k)
                            write(1, &s1[s_1], 1);
                    }
                }
                s_2++;
            }
            s_1++;
        }
    }
    write(1, "\n", 1);
}
