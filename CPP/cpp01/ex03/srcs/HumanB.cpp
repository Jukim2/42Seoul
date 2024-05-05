#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{

}

HumanB::~HumanB()
{

}

void	HumanB::setWeapon(Weapon& w)
{
	this->weapon = &w;
}

void	HumanB::attack()
{
	if (!weapon)
	{
		std::cout << "Give me some weapon!!" << std::endl;
		return;
	}
	std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}