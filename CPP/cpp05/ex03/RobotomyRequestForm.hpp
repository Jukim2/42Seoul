#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& name, const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& cpy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm();
		virtual void execute(const Bureaucrat& executor) const;
};

#endif
