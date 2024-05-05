#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type("noType")
{

}

AMateria::AMateria(std::string const &type) : type(type)
{

}

AMateria::AMateria(const AMateria& copy)
{
    *this = copy;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
    (void) rhs;
    return (*this);
}

AMateria::~AMateria()
{
    
}

std::string const & AMateria::getType() const
{
    return (type);
}

void AMateria::use(ICharacter& target)
{
    (void) target;
    std::cout << "No use..." << std::endl;
}