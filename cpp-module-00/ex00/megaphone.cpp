#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for(int i = 1; av[i]; i++)
        {
            for(int j = 0; av[i][j]; j++)
                std::cout << static_cast<char>(std::toupper(av[i][j]));
        }
    }
    std::cout<<std::endl;
    return (0);
}