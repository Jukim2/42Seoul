#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	*this = copy;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
		*brain = *(rhs.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (brain);
}

void Cat::makeSound() const
{
	std::cout << "Meow~ Meow~ Meow~" << std::endl;
}