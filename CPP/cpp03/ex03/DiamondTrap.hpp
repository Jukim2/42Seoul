#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;

    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& copy);
        DiamondTrap& operator=(const DiamondTrap& rhs);
        ~DiamondTrap();

        std::string getName() const;
        void printInfos() const;
        void whoAmI() const;
        void attack(const std::string&);
};

#endif