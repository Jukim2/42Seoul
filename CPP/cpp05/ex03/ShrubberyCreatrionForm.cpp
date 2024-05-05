#include "ShrubberyCreatrionForm.hpp"

ShrubberyCreatrionForm::ShrubberyCreatrionForm() : AForm("sForm", 145, 137), target("noTarget")
{
}

ShrubberyCreatrionForm::ShrubberyCreatrionForm(const std::string& name, const std::string& target) : AForm(name, 145, 137), target(target)
{
}

ShrubberyCreatrionForm::ShrubberyCreatrionForm(const ShrubberyCreatrionForm &cpy)
{
	*this = cpy;
}

ShrubberyCreatrionForm &ShrubberyCreatrionForm::operator=(const ShrubberyCreatrionForm &rhs)
{
	if (this != &rhs)
		target = rhs.target;
	return (*this);
}

ShrubberyCreatrionForm::~ShrubberyCreatrionForm()
{
}

void ShrubberyCreatrionForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	
	std::cout << "Create a file " << target << "_shrubbery" << std::endl;
}
