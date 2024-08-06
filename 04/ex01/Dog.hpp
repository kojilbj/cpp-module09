#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog& src);
		~Dog(void);

		Dog& operator=(const Dog& src);
		void	makeSound(void) const;

	private:
		Brain	*brain;
};

#endif