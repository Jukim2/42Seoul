#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("NOTYPE")
{	
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "Animal Sound!!!" << std::endl;
}