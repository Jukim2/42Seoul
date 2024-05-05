#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("pForm", 25, 5), target("noTarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name, const std::string& target) : AForm(name, 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy)
{
	*this = cpy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
		target = rhs.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	
	std::cout << target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}
