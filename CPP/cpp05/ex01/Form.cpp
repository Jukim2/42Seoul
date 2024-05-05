#include "Form.hpp"

Form::Form() 
: name("noname"), isSigned(false), signGrade(150), executeGrade(150)
{
}

Form::Form(const std::string& name, const int& signGrade, const int& executeGrade)
: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooHighException();
	else if (signGrade < 1 || executeGrade < 1)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) 
: name(copy.name), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	*this = copy;
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		isSigned = rhs.isSigned;
	}
	return (*this);
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
	return (name);
}

const bool &Form::getIsSigned() const
{
	return (isSigned);
}

const int &Form::getSignGrade() const
{
	return (signGrade);
}

const int &Form::getExecuteGrade() const
{
	return (executeGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	else
		isSigned = true;
}

std::ostream& operator<<(std::ostream&os, const Form& form)
{
	os	<< "Form name : " << form.getName() << '\n'
		<< "Form signed : " << form.getIsSigned() << '\n'
		<< "Form signGrade : " << form.getSignGrade() << '\n'
		<< "Form executeGrade : " << form.getExecuteGrade() << std::endl;

	return (os);
}
