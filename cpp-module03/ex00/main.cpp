#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap *soldiers = new ClapTrap[3];
    ClapTrap clapTrap("Target");
    for(int i = 0; i < 2; i++)
    {
        soldiers[i].attack("enemy1");
        clapTrap.takeDamage(2);
    }
    clapTrap.attack("enemy2");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);
    delete[] soldiers;
    return (0);
}