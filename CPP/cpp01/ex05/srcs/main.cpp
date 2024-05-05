#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl harl;
    harl.complain("debug");
    std::cout << std::endl;
    harl.complain("info");
    std::cout << std::endl;
    harl.complain("warning");
    std::cout << std::endl;
    harl.complain("error");
    std::cout << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
}