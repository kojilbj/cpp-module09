#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <unistd.h>

int	main(void)
{

	{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	}
	std::cout << "======Original Test Constructor=========" << std::endl;
	{
		Dog	dog;
		Cat	cat;
	{
		std::cout << "-------Copy Constructor Test-------" << std::endl;
		Dog tmpDog = dog;
		Cat tmpCat = cat;
	}
	{
		std::cout << "-------Copy Assignment Test-------" << std::endl;
		Dog tmpDog;
		tmpDog = dog;
		Cat tmpCat;
		tmpCat = cat;
	}
	std::cout << "======Original Test Destructor=========" << std::endl;
	}

//	Animal	animal;

	return 0;
}
