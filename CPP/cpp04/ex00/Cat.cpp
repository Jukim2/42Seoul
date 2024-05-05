#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow~ Meow~ Meow~" << std::endl;
}