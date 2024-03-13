#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
    private:
        std::string type;
    
    public:
        Weapon(std::string type);
        Weapon();
        ~Weapon();
        std::string  getType();
        void setType(std::string type);
};

#endif
