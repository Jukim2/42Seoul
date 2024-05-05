#include "ClapTrap.hpp"

int main()
{
    ClapTrap trap1("UltraTrap");

    trap1.printInfos();
    for (int i = 0; i < 11; i++)
    {
        trap1.attack("enemy");
    }
    trap1.printInfos();

}