#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp" 
#include "Base.hpp"


Base* generate()
{
    std::srand(std::time(0));
    Base *randObject = 0;

    int randomNumber = std::rand() % 3;
    if (randomNumber == 0)
        randObject = new A();
    else if (randomNumber == 1)
        randObject = new B();
    else if (randomNumber == 2)
        randObject = new C();

    return randObject;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (const std::bad_cast&) {}
}


int main() 
{
    Base* p = generate();
    identify(p);
    identify(*p);

    delete p;
    return 0;
}
