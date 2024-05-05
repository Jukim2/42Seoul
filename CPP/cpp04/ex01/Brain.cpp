#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
    *this = copy;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = rhs.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
