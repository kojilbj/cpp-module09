#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class	Animal
{
	public:
		Animal(void);
		Animal(const Animal& src);
		virtual	~Animal(void);

		Animal&	operator=(const Animal& src);

		virtual void	makeSound(void) const = 0;
		const std::string	getType(void) const;

	protected:
		std::string	type;
};

#endif