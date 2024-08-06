#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type_ = "WrongCat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Myaaaw" << std::endl;
}