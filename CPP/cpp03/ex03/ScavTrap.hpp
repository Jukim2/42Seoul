#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap
{
    protected:
        int hp;
        int ep;
        int ad;

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& copy);
        ScavTrap& operator=(const ScavTrap& rhs);
        ~ScavTrap();

        int getHp() const;
        int getEp() const;
        int getAd() const;
        void setHp(int hp);
        void setEp(int ep);
        void setAd(int ad);
        
        void attack(const std::string& target);
        void guardGate() const;
};

#endif