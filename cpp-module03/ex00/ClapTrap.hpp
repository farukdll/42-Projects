#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

    class ClapTrap{
        private:
            std::string name;
            int hitPoints;
            int energyPoints;
            int attackDamage;
            int maxHealthP;
        public:
            ClapTrap();
            ~ClapTrap();
            ClapTrap(std::string name);
            ClapTrap(const ClapTrap &copy);
            ClapTrap &operator=(const ClapTrap &clapTrap);
            void attack(const std::string& target);
            void takeDamage(unsigned int amount);
            void beRepaired(unsigned int amount);
    };

#endif