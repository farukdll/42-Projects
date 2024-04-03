#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::Base() {}

Base::~Base() {}

Base* Base::generate(void) {
    int random = std::rand() % 3;
    
    switch(random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return nullptr;
    }
}
        
void Base::identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "An error has occurred in the cast operation." << std::endl;
}
        
void Base::identify(Base& p) {
    try
    {
        if (dynamic_cast<A*>(&p))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B*>(&p))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C*>(&p))
            std::cout << "C" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
