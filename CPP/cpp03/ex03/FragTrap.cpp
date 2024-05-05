#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap(), hp(100), ep(100), ad(30)
{
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name), hp(100), ep(100), ad(30)
{
	setHitPoints(hp);
	setEnergyPoints(ep);
	setAttackDamage(ad);
	std::cout << "FragTrap constructor with name called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	hp = copy.hp;
	ep = copy.ep;
	ad = copy.ad;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Desturcor called" << std::endl;
}

int FragTrap::getHp() const
{
	return (hp);
}

int FragTrap::getEp() const
{
	return (ep);
}

int FragTrap::getAd() const
{
	return (ad);
}

void FragTrap::setHp(int hp)
{
	this->hp = hp;
}

void FragTrap::setEp(int ep)
{
	this->ep = ep;
}

void FragTrap::setAd(int ad)
{
	this->ad = ad;
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