#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <math.h>
#include "ScalarConverter.hpp"

template <typename A, typename B, typename C, typename D>
void printResult(const A& cChar, const B& cInt, const C& cFloat, const D& cDouble)
{
    std::cout   << "char : " << cChar << std::endl
                << "int : " << cInt << std::endl
                << "float : " << cFloat << "f" << std::endl
                << "double : " << cDouble << std::endl;
}

void convertToOtherType(const float& cfloat, const double& cDouble)
{
    if (cfloat - std::numeric_limits<int>::max() >= 1 || std::numeric_limits<int>::min() - cfloat >= 1 || isnan(cDouble))
        printResult<std::string, std::string, float, double>("impossible", "impossible", cfloat, cDouble);
        // char int impossible
    else if (cfloat > 127)
        printResult<std::string, int, float, double>("impossible", static_cast<int>(cfloat), cfloat, cDouble);
        // char impossible
    else if (cfloat <= 32)
        printResult<std::string, int, float, double>("Non displayable", static_cast<int>(cfloat), cfloat, cDouble);
        // char not displayable
    else
        printResult<char, int, float, double>(static_cast<char>(cfloat), static_cast<int>(cfloat), cfloat, cDouble);
}


void convertCharToOther(const char& ch)
{
    if (!isprint(ch))
    {
        std::cout << "Unavailable char" << std::endl;
        return;
    }
    if (std::isdigit(ch))
        printResult<char, int, float, double>(ch, static_cast<int>(ch - '0'), static_cast<float>(ch - '0'), static_cast<double>(ch - '0'));
    else
        printResult<char, int, float, double>(ch, static_cast<int>(ch), static_cast<float>(ch), static_cast<double>(ch));
}

template <typename T>
bool isConvertibleTo(const std::string& str, T& conversion) 
{
    std::istringstream iss(str);

    return iss >> conversion && iss.peek() == EOF;
}

void ScalarConverter::convert(const std::string& str)
{
    char    convertedChar;
    int     convertedInt;
    float   convertedFloat;
    double  convertedDouble;
    int     len = str.length();
    char    *pos;

    if (len == 0 || std::isspace(str[0]))
    {
        std::cout << "Impossible to handle" << std::endl;
        return;
    }
    if (isConvertibleTo<char>(str, convertedChar))
        convertCharToOther(convertedChar);
    else if (isConvertibleTo<int>(str, convertedInt))
        convertToOtherType(static_cast<float>(convertedInt), static_cast<double>(convertedInt));
    else
    {
        if ((convertedFloat = strtof(str.c_str(), &pos)) && *pos == 'f' && str[len - 1] == 'f')
            convertToOtherType(convertedFloat, static_cast<double>(convertedFloat));
        else if ((convertedDouble = strtod(str.c_str(), &pos)) && *pos == '\0')
            convertToOtherType(static_cast<float>(convertedDouble), convertedDouble);
        else
        {
            std::cout << "Impossible to handle" << std::endl;
        }
    }
}

ScalarConverter::ScalarConverter()
{
    
}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy)
{
    (void)cpy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    (void)rhs;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{

}