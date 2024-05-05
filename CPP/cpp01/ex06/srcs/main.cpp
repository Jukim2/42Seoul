#include "Utility.hpp"
#include "Harl.hpp"

int main()
{
    // std::cout << Utility::jenkinsHash("debug")%1009 << std::endl;
    // std::cout << Utility::jenkinsHash("info")%1009 << std::endl;
    // std::cout << Utility::jenkinsHash("warning")%1009 << std::endl;
    // std::cout << Utility::jenkinsHash("error")%1009 << std::endl;
    // std::cout << Utility::jenkinsHash("DEBUG")%1009 << std::endl;
    // std::cout << Utility::jenkinsHash("INFO")%1009 << std::endl;
    // std::cout << Utility::jenkinsHash("WARNING")%1009 << std::endl;
    // std::cout << Utility::jenkinsHash("ERROR")%1009 << std::endl;
    Harl harl;
    harl.complain("debug");
    harl.complain("info");
    harl.complain("INFO");

}