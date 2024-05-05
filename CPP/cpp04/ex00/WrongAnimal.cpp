#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	type = "NOTYPE";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	*this = copy;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Sound!!!" << std::endl;
}