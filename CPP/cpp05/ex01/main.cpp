#include "Form.hpp"

int main()
{
	std::string formName = "Promotion";

	Form form(formName, 100, 100);
	Bureaucrat kelly("Kelly", 90);
	Bureaucrat bona("Bona", 110);

	try
	{
		std::cout << form << std::endl;
		form.beSigned(kelly);
		std::cout << '\n' << form;
		form.beSigned(bona);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Form form ("Promotion", 3, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}