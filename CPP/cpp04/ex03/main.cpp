#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    std::cout << "-------------------Default-----------------------" << std::endl;
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;

    std::cout << "-------------------Character copy-----------------------" << std::endl;
    Character* amy = new Character("amy");
    Character* john = new Character("john");

    amy->equip(src->createMateria("ice"));
    amy->equip(src->createMateria("cure"));

    *john = *amy;
    john->unequip(1);

    delete amy;
    delete john;
    delete src;
    return 0;
}