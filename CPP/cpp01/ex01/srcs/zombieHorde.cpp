#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zomHorde;

	zomHorde = new Zombie[N];
	for (int idx = 0; idx < N; idx++)
	{
		zomHorde[idx].setName(name);
	}
	return (zomHorde);
}