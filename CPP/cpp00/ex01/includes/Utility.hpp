#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include <iostream>

class Utility
{
	public :
		static int	isOnlyDigit(std::string str);
		static void	setInput(std::string &str);
		static void	fixCinErr();
		static void	setNumInput(std::string &str);
};

#endif