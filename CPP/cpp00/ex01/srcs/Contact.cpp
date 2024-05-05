#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{
	
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, \
			std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName()
{
	return (firstName);
}

std::string	Contact::getLastName()
{
	return (lastName);
}

std::string	Contact::getNickName()
{
	return (nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (phoneNumber);
}

std::string Contact::getDarkestSecret()
{
	return (darkestSecret);
}
