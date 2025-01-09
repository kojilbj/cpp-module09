#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
	this->type_ = "Animal";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type_ = other.type_;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
		this->type_ = other.type_;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "????" << std::endl;
}

const std::string Animal::getType(void) const
{
	return this->type_;
}
