#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreatrionForm.hpp"
#include "Intern.hpp"
// 145 137
// 72 45
// 25 5

int main()
{
    Bureaucrat jay("jay", 30);
    Intern albert;
    AForm *form;

    form = albert.makeForm("wrong request", "home");
    form = albert.makeForm("robotomy request", "home");
    std::cout << *form;
    jay.signForm(*form);
    jay.executeForm(*form);
    delete form;
}