#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie	z1 = Zombie("normal Zombie");
	Zombie	*z2 = newZombie("pointer Zombie");

	z1.announce();
	z2->announce();
	randomChump("randomZombie");
	delete(z2);
}