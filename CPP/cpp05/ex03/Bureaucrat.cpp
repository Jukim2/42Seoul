#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("noname"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : name(name), grade(grade)
{
	if (grade > 150)
	{
		throw GradeTooHighException();
	}
	else if (grade < 1)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		grade = rhs.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
	return (name);
}

const int& Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade == 150)
		throw GradeTooHighException();
	else
		grade++;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 1)
		throw GradeTooLowException();
	else
		grade--;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade(); 
	return (os);
}

void Bureaucrat::signForm(AForm& form) const
{
	if (form.getSignGrade() >= grade)
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat " << name << " signed form " << form.getName() << std::endl; 
	}
	else
		std::cout << "Bureaucrat " << name << " couldn't sign form " << form.getName() << " because of Low grade" << std::endl;
}

void Bureaucrat::executeForm(const AForm&form) const
{
	if (!form.getIsSigned())
		std::cout << "Form is not signed" << std::endl;
	else if (grade > form.getExecuteGrade())
		std::cout << name << " need higher grade" << std::endl;
	else
	{
		std::cout << name << " executed " << form.getName() << std::endl;
		form.execute(*this);
	}
}
