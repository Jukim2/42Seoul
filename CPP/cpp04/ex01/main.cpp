#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
	std::cout << "------------- Constructors -------------" << std::endl;
	Animal* animalArray[4];

	std::cout << "------------- Making Animal -------------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animalArray[i] = new Dog();
		else
			animalArray[i] = new Cat();
		animalArray[i]->makeSound();
		std::cout << "\n";
	}
	
	std::cout << "\n------------- Destructors -------------" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete animalArray[i];
		std::cout << "\n";
	}

	std::cout << "------------- Fill Brain -------------" << std::endl;
	Dog* bullDog = new Dog();
	Dog* chiwawa = new Dog();
	
	for (int idea = 0; idea < 10; idea++)
	{
		bullDog->getBrain()->ideas[idea] = "bull..";
		chiwawa->getBrain()->ideas[idea] = "chi...";
	}
	
	*chiwawa = *bullDog;
	delete (bullDog);
	std::cout << chiwawa->getBrain()->ideas[0] << std::endl;
	delete (chiwawa);
	return 0;
}