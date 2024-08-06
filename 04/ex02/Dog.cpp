#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Dog constructor called" << std::endl;
	this->brain = new Brain;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "Baaaw" << std::endl;
}