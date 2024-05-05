#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap constructor with name called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap (copy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
   if (getEnergyPoints() < 1 || getHitPoints() < 1)
   {
        std::cout << "No points" << std::endl;
		return;
   }
    setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
	<< getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() const
{
    std::cout << "ScavTrap is Now on a Gate Keeper Mode" << std::endl;
}