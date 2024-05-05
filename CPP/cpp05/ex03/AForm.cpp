#include "AForm.hpp"

AForm::AForm() 
: name("noname"), isSigned(false), signGrade(150), executeGrade(150)
{
}

AForm::AForm(const std::string& name, const int& signGrade, const int& executeGrade)
: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooHighException();
	else if (signGrade < 1 || executeGrade < 1)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) 
: name(copy.name), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	*this = copy;
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		isSigned = rhs.isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
	return (name);
}

const bool &AForm::getIsSigned() const
{
	return (isSigned);
}

const int &AForm::getSignGrade() const
{
	return (signGrade);
}

const int &AForm::getExecuteGrade() const
{
	return (executeGrade);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	else
		isSigned = true;
}

std::ostream& operator<<(std::ostream&os, const AForm& form)
{
	os	<< "Form name : " << form.getName() << '\n'
		<< "Form signed : " << form.getIsSigned() << '\n'
		<< "Form signGrade : " << form.getSignGrade() << '\n'
		<< "Form executeGrade : " << form.getExecuteGrade() << std::endl;

	return (os);
}
