#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& cpy);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter();
    public:
        static void convert(const std::string& str);
};


#endif