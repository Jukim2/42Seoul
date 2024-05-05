#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("noname_clap_trap"), FragTrap("noname"), ScavTrap("noname"), name("noname")
{

}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), FragTrap(name), ScavTrap(name), name(name)
{
    setHitPoints(FragTrap::hp);
    setEnergyPoints(ScavTrap::ep);
    setAttackDamage(FragTrap::ad);
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
    name = copy.name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        ScavTrap::operator=(rhs);
        FragTrap::operator=(rhs);
        name = rhs.name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{

}

std::string DiamondTrap::getName() const
{
    return (name);
}

void DiamondTrap::printInfos() const
{
	std::cout << "name : " << name
	<< " hitPoints : " << getHitPoints()
	<< " energyPoints : " << getEnergyPoints()
	<< " attackDamage : " << getAttackDamage()
	<<std::endl;
}

void DiamondTrap::attack(const std::string& str)
{
    ScavTrap::attack(str);
}

void DiamondTrap::whoAmI() const
{
    std::cout << "Name : " << name << " ClapTrap name : " << ClapTrap::name << std::endl;
}