#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria
{
    protected:
        std::string type;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& copy);
        AMateria& operator=(const AMateria& rhs);
        virtual ~AMateria();
        
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif