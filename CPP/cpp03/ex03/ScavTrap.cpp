#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), hp(100), ep(50), ad(20)
{
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), hp(100), ep(50), ad(20)
{
    setHitPoints(hp);
    setEnergyPoints(ep);
    setAttackDamage(ad);
    std::cout << "ScavTrap constructor with name called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    hp = copy.hp;
    ep = copy.ep;
    ad = copy.ad;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        hp = rhs.hp;
		ep = rhs.ep;
		ad = rhs.ad;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Desturcor called" << std::endl;
}

int ScavTrap::getHp() const
{
	return (hp);
}

int ScavTrap::getEp() const
{
	return (ep);
}

int ScavTrap::getAd() const
{
	return (ad);
}

void ScavTrap::setHp(int hp)
{
	this->hp = hp;
}

void ScavTrap::setEp(int ep)
{
	this->ep = ep;
}

void ScavTrap::setAd(int ad)
{
	this->ad = ad;
}

void ScavTrap::attack(const std::string& target)
{
   if (getEnergyPoints() < 1 || getHitPoints() < 1)
   {
        std::cout << "No Energy" << std::endl;
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