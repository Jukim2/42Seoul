#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap constructor with name called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Desturcor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
   if (getEnergyPoints() < 1 || getHitPoints() < 1)
   {
        std::cout << "No points" << std::endl;
		return;
   }
    setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "FragTrap " << getName() << " attacks " << target << ", causing "
	<< getAttackDamage() << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() const
{
    std::cout << "Positive High fives!!" << std::endl;
}