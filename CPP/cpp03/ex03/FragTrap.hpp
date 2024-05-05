#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap
{
    protected:
        int hp;
        int ep;
        int ad;

    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        FragTrap& operator=(const FragTrap& rhs);
        ~FragTrap();

        int getHp() const;
        int getEp() const;
        int getAd() const;
        void setHp(int hp);
        void setEp(int ep);
        void setAd(int ad);

        void attack(const std::string& target);
        void highFivesGuys() const;
};

#endif