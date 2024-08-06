#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	this->type_ = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Myaaaw" << std::endl;
}