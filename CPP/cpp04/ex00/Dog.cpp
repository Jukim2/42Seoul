#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bow Bow! Bow Bow!" << std::endl;
}