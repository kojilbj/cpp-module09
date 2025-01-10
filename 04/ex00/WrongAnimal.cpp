#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = src.type;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "????" << std::endl;
}

const	std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
