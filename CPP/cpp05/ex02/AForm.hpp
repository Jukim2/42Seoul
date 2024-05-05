#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;

	public:
		AForm();
		AForm (const std::string& name, const int& signGrade, const int& executeGrade);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& rhs);
		virtual ~AForm();
		const std::string& getName() const;
		const bool& getIsSigned() const;
		const int& getSignGrade() const;
		const int& getExecuteGrade() const;
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& executor) const = 0;
	
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

	class NotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Form is not signed");
			}
	};
};

std::ostream& operator<<(std::ostream&os, const AForm& form);

#endif