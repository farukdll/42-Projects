#include "iter.hpp"

template <typename T>
void printElement(T const &element)
{
    std::cout << element << std::endl;
}


int main()
{
    std::cout << "-- 👻 Int Elements 👻 --" << std::endl;
    int intArray[] = {1,2,3,};
    iter(intArray, 3, printElement<int>);

    std::cout << "-- 👻 Double Elements 👻 --" << std::endl;
    double doubleArray[] = {1.5, 2.5, 3.5};
    iter(doubleArray, 3, printElement<double>);

    std::cout << "-- 👻 String Elements 👻 --" << std::endl;
    std::string stringArray[] = {"Elma", "Armut", "Muz"};
    iter(stringArray, 3, printElement<std::string>);

    return 0;
}
