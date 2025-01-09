#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	this->type_ = "Cat";
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type_ = other.type_;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
		this->type_ = other.type_;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Myaaaw" << std::endl;
}
