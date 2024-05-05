#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(const Ice &copy) : AMateria(copy)
{

}

Ice& Ice::operator=(const Ice&rhs)
{
    if (this != &rhs)
    {
        type = rhs.type;
    }
    return (*this);
}

Ice::~Ice()
{

}

AMateria* Ice::clone() const
{
    AMateria *amateria = new Ice();
    
    return (amateria);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}