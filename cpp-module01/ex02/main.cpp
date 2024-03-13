#include <iostream>

int main() {
    std::string brain("HI THIS IS BRAIN");
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "Memory adress of string: " << &brain << std::endl;
    std::cout << "Memory adress of stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory adress of stringREF: " << &stringREF << std::endl;

    std::cout << "Value of the string: " << brain << std::endl;
    std::cout << "Value of the stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of the stringREF: " << stringREF << std::endl;
}
