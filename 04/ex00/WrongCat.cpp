#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "Wrong Cat copy constructor called" << std::endl;
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Wrong Cat assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Myaaaw" << std::endl;
}
