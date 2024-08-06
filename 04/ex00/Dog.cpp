#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Baaaw" << std::endl;
}