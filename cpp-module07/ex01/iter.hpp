#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(const T &element))
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
    
}
#endif
