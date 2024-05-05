#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("rForm", 72, 45), target("noTarget")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name, const std::string& target) : AForm(name, 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
{
	*this = cpy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
		target = rhs.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	
	if (std::rand() > 1073741823)
		std::cout << "dzzzz.... " << target << " Robotomized success" << std::endl;
	else
		std::cout << "dzzzz.... " << target << " Robotomized fail" << std::endl;
}
