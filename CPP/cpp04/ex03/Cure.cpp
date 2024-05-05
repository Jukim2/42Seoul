#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
    
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{

}

Cure& Cure::operator=(const Cure&rhs)
{
    if (this != &rhs)
    {
        type = rhs.type;
    }
    return (*this);
}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
    AMateria *amateria = new Cure();
    
    return (amateria);
}

void Cure::use(ICharacter& target)
{
        std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}