#include "Bureaucrat.hpp"

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
