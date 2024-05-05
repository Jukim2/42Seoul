#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreatrionForm.hpp"


Intern::Intern()
{
}

Intern::Intern(const Intern &cpy)
{
    (void)cpy;
}

Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    return (*this);
}

Intern::~Intern()
{
}

AForm* makePForm(std::string name, std::string target)
{
    PresidentialPardonForm *pForm = new PresidentialPardonForm(name, target);
    std::cout << "Presitial Pardon Form is made. name : " << name << " target : " << target << std::endl;
    return (pForm);
}

AForm* makeSForm(std::string name, std::string target)
{
    ShrubberyCreatrionForm *sForm = new ShrubberyCreatrionForm(name, target);
    std::cout << "Shrubbery Creation Form is made. name : " << name << " target : " << target << std::endl;
    return (sForm);
}

AForm* makeRForm(std::string name, std::string target)
{
    RobotomyRequestForm *rForm = new RobotomyRequestForm(name, target);
    std::cout << "Robotomy Request Form is made. name : " << name << " target : " << target << std::endl;
    return (rForm);
}

AForm* Intern::makeForm(const std::string &name, const std::string &target)
{   
    AForm* (*ptrs[3])(std::string, std::string);
    ptrs[0] = makeRForm;
    ptrs[1] = makePForm;
    ptrs[2] = makeSForm;
    if (!(name == "robotomy request" || name == "shrubbery creation" || name == "presidential pardon"))
    {
        std::cout << "Error : no matching form" << std::endl;
        return nullptr;
    }
    return (ptrs[name[5]%3](name, target));
}
