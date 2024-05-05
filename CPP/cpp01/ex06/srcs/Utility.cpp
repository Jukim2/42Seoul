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

void	Utility::fixCinErr()
{
    if (std::cin.fail())
    {
        if (std::cin.eof())
        {
            std::cin.clear();
            clearerr(stdin);
        }
    }
}

size_t  Utility::jenkinsHash(const std::string& str)
{
    size_t hash = 0;

    for (size_t idx = 0; idx < str.length(); idx++) {
        char c = str[idx];
        hash += static_cast<size_t>(c);
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}