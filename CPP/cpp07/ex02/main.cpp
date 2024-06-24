#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> arr(5);
    std::cout << "arr : " << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        arr[i] = 3;
        std::cout << "arr[" << i << "] : " << arr[i] << std::endl;
    }

    Array<int> arr2(arr);
    std::cout << "arr2 : " << std::endl;
    for (unsigned int i = 0; i < arr2.size(); i++)
    {
        std::cout << "arr2[" << i << "] : " << arr2[i] << std::endl;
    }

    std::cout << "\n--------- arr change value -----------" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        arr[i] = i;
        std::cout << "arr[" << i << "] : " << arr[i] << std::endl;
    }

    std::cout << "arr2 : " << std::endl;
    for (unsigned int i = 0; i < arr2.size(); i++)
    {
        std::cout << "arr2[" << i << "] : " << arr2[i] << std::endl;
    }

    Array<int> arr3 = arr;
    std::cout << "\n--------- arr3 -----------" << std::endl;
    for (unsigned int i = 0; i < arr3.size(); i++)
    {
        std::cout << "arr3[" << i << "] : " << arr3[i] << std::endl;
    }

    std::cout << "\n--------- arr change value -----------" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        arr[i] = i * 10;
        std::cout << "arr[" << i << "] : " << arr[i] << std::endl;
    }

    for (unsigned int i = 0; i < arr3.size(); i++)
    {
        std::cout << "arr3[" << i << "] : " << arr3[i] << std::endl;
    }

}