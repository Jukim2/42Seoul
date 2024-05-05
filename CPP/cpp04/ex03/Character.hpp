#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        AMateria *slot[4];
        std::string name;

    public:
        Character();
        Character(std::string name);
        Character(const Character& copy);
        Character& operator=(const Character& rhs);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};


#endif