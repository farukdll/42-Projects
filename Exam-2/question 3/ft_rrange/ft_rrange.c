#include <stdlib.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
    int *range;
    int n = start > end ? start - end + 1 : end - start + 1;
    int dir = start < end ? 1 : -1;

    range = malloc(sizeof(int) * n);
    while (n--)
    {
        range[n] = start;
        start += dir;
    }
    return range;
}

/*
int main()
{
    int *tab = ft_rrange(1, 5);
    int i = 0;
    while (i < 5)
    {
        printf("%d\n", tab[i]);
        i++;
    }
}
*/

//-----------------------------------------------------------------

   start > end ? start - end + 1 : end - start + 1;

//  I am explaining the definition you see above for those who do not know or see it for the first time.

//  This means an if else condition

//  We can describe this situation as follows.

/*
    int k;
    int dir;

    if (start > end)
        k = start - end + 1;
    else
        k = end - start + 1;

    if (start < end)
        dir = 1;
    else
        dir = -1;
*/

//-----------------------------------------------------------------
