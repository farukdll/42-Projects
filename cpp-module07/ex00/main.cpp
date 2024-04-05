#include "whatever.hpp"

template<typename T>
void swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

template<typename T>
T min(T x, T y) {
    return (y <= x) ? y : x;
}

template<typename T>
T max(T x, T y) {
    return (x <= y) ? y : x;
}

int main(void) {
    
    int a = 3;
    int b = 3;
    
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    
    return 0;
}
