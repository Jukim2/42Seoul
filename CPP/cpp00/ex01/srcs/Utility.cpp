#include "Utility.hpp"

int	Utility::isOnlyDigit(std::string str)
{
        for (unsigned long idx = 0; idx < str.length(); idx++)
        {
            if (!isdigit(str[idx]))
                return (0);
        }
        return (1);
}

void	Utility::setInput(std::string &str)
{
    while (true) {
        if (getline(std::cin, str))
            break ;
        fixCinErr();
    }
}

void	Utility::setNumInput(std::string &str)
{
    while (true) {
        if (getline(std::cin, str) && Utility::isOnlyDigit(str))
            break ;
        fixCinErr();
        std::cout << "Phone Number(Only digit) : ";
    }
}

void	Utility::fixCinErr()
{
    if (std::cin.eof())
    {
        std::cin.clear();
        clearerr(stdin);
    }
}