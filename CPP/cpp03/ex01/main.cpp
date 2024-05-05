#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("UltraTrap");
    
    scavTrap.printInfos();
    scavTrap.setEnergyPoints(200);
    scavTrap.attack("enemy");
    scavTrap.printInfos();
}