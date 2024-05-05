#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("john", 150);
		a.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat b("keily", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat c("zeno", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Bureaucrat d("knuth", 3);
	std::cout << d;
		
}
		