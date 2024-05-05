#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	tmpzmb = Zombie(name);
	tmpzmb.announce();
}