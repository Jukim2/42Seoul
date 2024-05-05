#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Base * generate(void);
// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
// void identify(Base* p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// void identify(Base& p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden.

Base* generate()
{
    std::srand(std::time(0));

    int randomNumber = std::rand();
    if (randomNumber == 0)
    {
        std::cout << "A generated" << std::endl;
        return (new A);
    }
    else if (randomNumber == 1)
    {
        std::cout << "B generated" << std::endl;
        return (new B);
    }
    else if (randomNumber == 2)
    {
        std::cout << "C generated" << std::endl;
        return (new C);
    }
}

void identify(Base* p)
{

}

void identify(Base& p)
{

}

int main()
{

}