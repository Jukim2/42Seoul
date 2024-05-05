#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		int		idx;
		int		cnt;
		Contact contacts[8];

	public:
		PhoneBook();
		~PhoneBook();
		void    addContact();
		void    searchContact();
		void	printName(std::string name, char seperator);
		void	showContact(int inputIdx);
};

#endif