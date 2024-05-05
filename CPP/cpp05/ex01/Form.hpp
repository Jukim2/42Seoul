#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;

	public:
		Form();
		Form (const std::string& name, const int& signGrade, const int& executeGrade);
		Form(const Form& copy);
		Form& operator=(const Form& rhs);
		~Form();
		const std::string& getName() const;
		const bool& getIsSigned() const;
		const int& getSignGrade() const;
		const int& getExecuteGrade() const;
		void beSigned(const Bureaucrat& bureaucrat);
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Grade is too high");
			}
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Grade is too low");
			}
	};
};

std::ostream& operator<<(std::ostream&os, const Form& form);

#endif