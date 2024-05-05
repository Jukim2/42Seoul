#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreatrionForm.hpp"
#include <iostream>
// 145 137
// 72 45
// 25 5

int main()
{
    Bureaucrat james("James", 140);
    Bureaucrat kelly("kelly", 25);

    ShrubberyCreatrionForm sForm("sForm", "sTarget");
    RobotomyRequestForm rForm("rForm", "rTarget");
    PresidentialPardonForm pForm("pForm", "pTarget");

    std::cout << "----------------------- Form Information ----------------------------" << std::endl;
    std::cout << sForm << '\n' << rForm << '\n' << pForm << std::endl;

    std::cout << "----------------------- Shrubbery SIGN ----------------------------" << std::endl;
    james.signForm(sForm);
    james.executeForm(sForm);
    kelly.executeForm(sForm);
    
    std::cout << "----------------------- Presidential SIGN ----------------------------" << std::endl;
    try
    {
        pForm.execute(james);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        kelly.signForm(pForm);
        pForm.execute(james);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}