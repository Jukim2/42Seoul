#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int main()
{
	Zombie	*zomHorde;

	zomHorde = zombieHorde(3, "billy");
	for (int i = 0; i < 3; i++)
	{
		zomHorde[i].announce();
	}
	delete [] zomHorde;
}