#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    DiamondTrap diamondTrap("Olivia");
    DiamondTrap diamondTrap2("julia");

    std::cout << std::endl;

    diamondTrap.whoAmI();

    std::cout << std::endl;

    diamondTrap2.whoAmI();

    std::cout << std::endl;

    diamondTrap.printInfos();

    std::cout << std::endl;

}