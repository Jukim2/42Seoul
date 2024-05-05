#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();
		const std::string& getName() const;
		const int& getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form) const;
		
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Grade is too high!";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Grade is too Low!";
			}
	};

};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif