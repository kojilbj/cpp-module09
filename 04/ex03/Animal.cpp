#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = src.type;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& src)
{
	if (this != &src)
		this->type = src.type;
	return (*this);
}

const	std::string	Animal::getType(void) const
{
	return (this->type);
}
