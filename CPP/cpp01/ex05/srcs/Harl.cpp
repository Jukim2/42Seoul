#include "Harl.hpp"
#include "Utility.hpp"
#include <iostream>

Harl::Harl()
{
    hash[Utility::jenkinsHash("DEBUG") % 1009] = "DEBUG";
    hash[Utility::jenkinsHash("INFO") % 1009] = "INFO";
    hash[Utility::jenkinsHash("WARNING") % 1009] = "WARNING";
    hash[Utility::jenkinsHash("ERROR") % 1009] = "ERROR";
    hash[Utility::jenkinsHash("debug") % 1009] = "debug";
    hash[Utility::jenkinsHash("info") % 1009] = "info";
    hash[Utility::jenkinsHash("warning") % 1009] = "warning";
    hash[Utility::jenkinsHash("error") % 1009] = "error";
    funcPtr[0] = &Harl::debug;
    funcPtr[1] = &Harl::info;
    funcPtr[2] = &Harl::warning;
    funcPtr[3] = &Harl::error;
}

Harl::~Harl()
{

}

void    Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std:: endl;
}

void    Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string value = hash[Utility::jenkinsHash(level) % 1009];

    switch (Utility::jenkinsHash(level) % 1009)
    {
        case 231 :
        case 934 :  if (level == value)
                    {
                        (this->*funcPtr[3])();
                    }
                    break;
        case 315 :
        case 522 :  if (level == value)
                    {
                        (this->*funcPtr[2])();
                    } 
                    break;
        case 683 :
        case 919 :  if (level == value)
                    {
                        (this->*funcPtr[1])();
                    }
                    break;
        case 515 :
        case 779 :  if (level == value)
                    {
                        (this->*funcPtr[0])();
                    }
                    break;
    }
}