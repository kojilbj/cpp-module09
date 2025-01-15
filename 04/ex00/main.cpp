#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	}

	{
	std::cout << "=======Copy Assignment Operator========" << std::endl;
	Dog	DogA;
	Dog	DogB;

	DogA = DogB;

	Cat	CatA;
	Cat	CatB;

	CatA = CatB;
	}
	{
	std::cout << "=======Self Assignment========" << std::endl;
	Dog	DogA;
	Dog	*DogB = &DogA;

	DogA = *DogB;

	Cat	CatA;
	Cat	*CatB = &CatA;

	CatA = *CatB;
	}

	{
	std::cout << "=======Wrong========" << std::endl;
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();
	std::cout << b->getType() << " " << std::endl;
	b->makeSound(); 
	a->makeSound();
	delete a;
	delete b;
	}
	return 0;
}
