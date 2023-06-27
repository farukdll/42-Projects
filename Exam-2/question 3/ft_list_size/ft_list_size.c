#include "ft_list.h"
//#include <stdlib.h>
//#include <stdio.h>

int ft_list_size(t_list *begin_list)
{
    if (begin_list == 0)
        return (0);
    else
        return (1 + ft_list_size(begin_list->next));
}
/*
int main()
{
    t_list *a = malloc(1000);
    t_list *b = malloc(1000);
    t_list *c = malloc(1000);

    a->next = b;
    b->next = c;
    printf("%d\n", ft_list_size(a));
}
*/
