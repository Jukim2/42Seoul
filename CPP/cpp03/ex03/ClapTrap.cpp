#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("noname"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Constructor with name argument called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		hitPoints = rhs.hitPoints;
		energyPoints = rhs.energyPoints;
		attackDamage = rhs.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (name);
}

int ClapTrap::getHitPoints() const
{
	return (hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (energyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (attackDamage);
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	this->attackDamage = attackDamage;
}

void ClapTrap::printInfos() const
{
	std::cout << "name : " << name
	<< " hitPoints : " << hitPoints
	<< " energyPoints : " << energyPoints
	<< " attackDamage : " << attackDamage
	<<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints < 1 || hitPoints < 1)
	{
		std::cout << "Can't do the action" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
	<< attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int prevHitPoints = hitPoints;

	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << "ClapTrap " << name << " gets damage " << amount
	<< " prevHitpoints : " << prevHitPoints << "currHitpoints : " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	int prevHitPoints = hitPoints;

	if (energyPoints < 1 || hitPoints < 1)
	{
		std::cout << "Can't do the action" << std::endl;
		return;
	}
	energyPoints--;
	hitPoints += amount;
	if (hitPoints > 10)
		hitPoints = 10;
	std::cout << "ClapTrap " << name << " gets repaired " << amount
	<< " prevHitpoints : " << prevHitPoints << "currHitpoints : " << hitPoints << std::endl;
}
