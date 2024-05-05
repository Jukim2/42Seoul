#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	*this = copy;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
		*brain = *(rhs.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (brain);
}
void Dog::makeSound() const
{
	std::cout << "Bow Bow! Bow Bow!" << std::endl;
}