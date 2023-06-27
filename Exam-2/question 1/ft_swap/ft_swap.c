#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
int main()
{
    int a;
    int b;

    a = 24; // a value
    b = 42; // b value
    printf("Before --> a = %d    b = %d\n", a, b);
    ft_swap(&a, &b);
    printf("After  --> a = %d    b = %d\n", a, b);
}
*/
