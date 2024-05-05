#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>

class Utility
{
	public :
		static int	    isOnlyDigit(std::string str);
		static void	    setInput(std::string &str);
		static void	    fixCinErr();
        static size_t   jenkinsHash(const std::string& str);
};

#endif
