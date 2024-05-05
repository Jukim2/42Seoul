#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        FragTrap& operator=(const FragTrap& rhs);
        ~FragTrap();

        void attack(const std::string& target);
        void highFivesGuys() const;
};

#endif