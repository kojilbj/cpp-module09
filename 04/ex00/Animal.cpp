#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
	this->type_ = "Animal";
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type_ = src.type_;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& src)
{
	if (this != &src)
		this->type_ = src.type_;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "????" << std::endl;
}

const	std::string	Animal::getType(void) const
{
	return (this->type_);
}