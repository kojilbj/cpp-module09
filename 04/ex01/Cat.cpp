#include "Cat.hpp"
#include <iostream>
#include "Brain.hpp"

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	this->type_ = "Cat";
	this->brain = new Brain;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Myaaaw" << std::endl;
}