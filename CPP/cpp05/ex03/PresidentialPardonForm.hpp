#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& name, const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& cpy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm();
		virtual void execute(const Bureaucrat& executor) const;
};

#endif
