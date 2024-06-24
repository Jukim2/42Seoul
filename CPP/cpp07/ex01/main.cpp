#include <iostream>
#include "iter.hpp"

int main()
{
    std::string strArr[3] = {"aa", "bb", "cc"};
    int intArr[3] = {1, 2, 3};

    iter(strArr, 3, func);
    iter(intArr, 3, func); 
}