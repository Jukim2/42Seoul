#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
	std::cout << "------------- Constructors -------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\n------------- type Functions -------------" << std::endl;
	std::cout << "Dog : " << dog->getType() << " " << std::endl;
	std::cout << "Cat : " << cat->getType() << " " << std::endl;
	std::cout << "WrongAnimal : " << wrongAnimal->getType() << " " << std::endl;
	std::cout << "WrongCat : " << wrongCat->getType() << " " << std::endl;

	std::cout << "\n------------- sound Functions -------------" << std::endl;
	std::cout << "Animal : ";
	meta->makeSound();
	std::cout << "Dog : ";
	dog->makeSound();
	std::cout << "Cat : ";
	cat->makeSound();
	std::cout << "WrongAnimal : ";
	wrongAnimal->makeSound();
	std::cout << "WrongCat : ";
	wrongCat->makeSound();

	std::cout << "\n------------- Destructors -------------" << std::endl;
	delete (meta);
	delete (dog);
	delete (cat);
	delete (wrongAnimal);
	delete (wrongCat);
	return 0;
}