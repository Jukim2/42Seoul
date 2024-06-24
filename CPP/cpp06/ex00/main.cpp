#include <iostream>
#include "ScalarConverter.hpp"

int main()
{
    // (void)argc;
    // ScalarConverter::convert(argv[1]);
    std::cout << "------------------------- Normal ------------------------------\n";
    ScalarConverter::convert("123");
    std::cout << '\n';
    ScalarConverter::convert("-123");
    std::cout << '\n';
    ScalarConverter::convert("33f");
    std::cout << '\n';
    ScalarConverter::convert("116516854f");
    std::cout << '\n';
    ScalarConverter::convert("f");
    std::cout << '\n';
    ScalarConverter::convert("z");

    std::cout << "\n------------------------- Big number ------------------------------\n";
    ScalarConverter::convert("15313135");
    std::cout << '\n';
    ScalarConverter::convert("12312312312311f");
    std::cout << '\n';
    ScalarConverter::convert("1351351564646468486546");
    std::cout << '\n';
    ScalarConverter::convert("-654156456456468486468486486468167167476874357475874758741358716387436817587436458456");
    std::cout << '\n';

    std::cout << "\n------------------------- Special case ------------------------------\n";
    ScalarConverter::convert("inf");
    std::cout << '\n';
    ScalarConverter::convert("-inf");
    std::cout << '\n';
    ScalarConverter::convert("nan");
    std::cout << '\n';
    ScalarConverter::convert("inff");
    std::cout << '\n';
}