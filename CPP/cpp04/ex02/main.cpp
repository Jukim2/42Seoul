#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
	Animal *animal = new Dog();
	animal->makeSound();
	delete(animal);
	
	return 0;
}