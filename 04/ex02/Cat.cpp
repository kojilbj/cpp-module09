#include "Cat.hpp"
#include <iostream>
#include "Brain.hpp"

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(const Cat& other)
{
	Brain *tmp;

	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
	tmp = new Brain(*(other.brain));
	this->brain = tmp;
}

Cat& Cat::operator=(const Cat& other)
{
	Brain *tmp;

	std::cout << "Cat assignment operator called" << std::endl;
	if (this == &other)
	{
		this->type = other.type;
		delete (this->brain);
		tmp = new Brain(*(other.brain));
		this->brain = tmp;
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete (this->brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Myaaaw" << std::endl;
}
