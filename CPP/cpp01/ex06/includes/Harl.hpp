#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
    private :
        void (Harl::*funcPtr[4])(void);
        std::string hash[1009];
    public :
        Harl();
        ~Harl();
        void debug();
        void info();
        void warning();
        void error();
        void complain(std::string level);
};

#endif