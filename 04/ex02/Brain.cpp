#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	int	i;

	std::cout << "Brain copy constructor called" << std::endl;
	i = 0;
	if (this != &src)
	{
		while (i < 100)
		{
			this->ideas_store_[i] = src.ideas_store_[i];
			i++;
		}
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& src)
{
	int	i;

	std::cout << "Brain assign operator called" << std::endl;
	i = 0;
	if (this != &src)
	{
		while (i < 100)
		{
			this->ideas_store_[i] = src.ideas_store_[i];
			i++;
		}
	}
	return (*this);
}