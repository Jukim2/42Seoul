#include <iostream>
#include <string>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "String Address : " << &str << std::endl;
	std::cout << "String Pointer Address : " << stringPTR  << std::endl;
	std::cout << "String Reference Address : " << &stringREF << std::endl;
	std::cout << "String Value : " << str << std::endl;
	std::cout << "String Pointer Value : " << *stringPTR << std::endl;
	std::cout << "String Reference Value : "<< stringREF << std::endl;
}