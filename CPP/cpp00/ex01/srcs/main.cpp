#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Utility.hpp"
#include <iostream>

int	main()
{
	PhoneBook phoneBook;
	std::string	cmd;

	std::cout << "Command(ADD / SEARCH / EXIT) : ";
	while (1)
	{
		while (getline(std::cin, cmd))
		{
			if (cmd == "ADD")
				phoneBook.addContact();
			else if (cmd == "SEARCH")
				phoneBook.searchContact();
			else if (cmd == "EXIT")
				exit (0);
			std::cout << "Command(ADD / SEARCH / EXIT) : ";
		}
		Utility::fixCinErr();
	}
	return (0);
}