#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	*this = copy;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow~ Meow~ Meow~" << std::endl;
}