#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Dog constructor called" << std::endl;
	this->brain = new Brain;
}

Dog::Dog(const Dog& other)
{
	Brain *tmp;

	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	tmp = new Brain(*(other.brain));
	this->brain = tmp;
}

Dog& Dog::operator=(const Dog& other)
{
	Brain *tmp;

	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete (this->brain);
		tmp = new Brain(*(other.brain));
		this->brain = tmp;
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete (this->brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "Baaaw" << std::endl;
}
