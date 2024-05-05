#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

Character::Character() : name("noname")
{
    for (int i = 0; i < 4; i++)
        slot[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
    for (int i = 0; i < 4; i++)
        slot[i] = NULL;
}

Character::Character(const Character& copy)
{
    *this = copy;
}

Character& Character::operator=(const Character& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {            
            if (slot[i] != NULL)
            {
                delete (slot[i]);
                slot[i] = NULL;
            }
            if (rhs.slot[i] != NULL)
            {            
                slot[i] = rhs.slot[i]->clone();
                MateriaSource::track(slot[i]);
            }
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (slot[i] != NULL && MateriaSource::isTrackable(slot[i]))
        {
            std::cout << name << " erase " << i << std::endl;
            MateriaSource::untrack(slot[i]);
            delete (slot[i]);
        }
    }
}

std::string const & Character::getName() const
{
    return (name);
}

void Character::equip(AMateria* m)
{
    if (m->getType() == "noType")
    {
        std::cout << "It is not good materia" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (slot[i] == NULL)
        {
            std::cout << "Equiped " << m->getType() << " at slot " << i << std::endl;
            slot[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (slot[idx] != NULL)
        slot[idx]->use(target);
    else
        std::cout << "No equipped materia" << std::endl;
}
