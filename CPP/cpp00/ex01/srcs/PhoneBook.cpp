#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Utility.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
	idx = 0;
}

PhoneBook::~PhoneBook()
{

}

void    PhoneBook::addContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "First Name: ";
	Utility::setInput(firstName);
	std::cout << "Last Name : ";
	Utility::setInput(lastName);
	std::cout << "Nick Name : ";
	Utility::setInput(nickName);
	std::cout << "Phone Number(Only digit) : ";
	Utility::setNumInput(phoneNumber);
	std::cout << "Darkest Secret : ";
	Utility::setInput(darkestSecret);
	if (firstName.empty() || lastName.empty() || nickName.empty()
		|| phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Some field is empty;" << std::endl;
		return ;
	}
	contacts[idx++] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	if (cnt < 8)
		cnt = idx;
	if (idx == 8)
		idx = 0;
}

void	PhoneBook::searchContact()
{
	int	contactIdx;

	std::cout << std::setfill(' ');
	for (int i = 0; i < cnt; i++)
	{
		std::cout << std::setw(10) << i << "|";
		printName(contacts[i].getFirstName(), '|');
		printName(contacts[i].getLastName(), '|');
		printName(contacts[i].getNickName(), '\0');
	}
	std::cout << "What contact do you want to see?" << std::endl;
	std::cin >> contactIdx;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	Utility::fixCinErr();
	showContact(contactIdx);
}

void	PhoneBook::showContact(int contactIdx)
{
	if (contactIdx < 0 || contactIdx > 7 || contactIdx >= cnt)
	{
		std::cout << "No matching contact" << std::endl;
		return;
	}
	else
	{
		std::cout << std::setw(20) << std::left << "FirstName : " << contacts[contactIdx].getFirstName() << std::endl;
		std::cout << std::setw(20) << std::left << "LastName : " << contacts[contactIdx].getLastName() << std::endl;
		std::cout << std::setw(20) << std::left << "NickName : " << contacts[contactIdx].getNickName() << std::endl;
		std::cout << std::setw(20) << std::left << "PhoneNumber : " << contacts[contactIdx].getPhoneNumber() << std::endl;
		std::cout << std::setw(20) << std::left << "DarkestSecret : " << contacts[contactIdx].getDarkestSecret() << std::endl;
	}
}

void	PhoneBook::printName(std::string name, char seperator)
{
	int	len;

	len = name.length();
	if (len == 0)
		return ;
	else if (len < 10)
	{
		std::cout << std::setw(10) << name;
		if (seperator)
			std::cout << seperator;
		else
			std::cout << std::endl;
	}
	else
	{
		std::cout << std::setw(10) << name.substr(0,9) + '.';
		if (seperator)
			std::cout << seperator;
		else
			std::cout << std::endl;
	}
}
