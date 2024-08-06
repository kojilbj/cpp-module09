#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& src);
		~WrongAnimal(void);

		WrongAnimal&	operator=(const WrongAnimal& src);

		void	makeSound(void) const;
		const std::string	getType(void) const;

	protected:
		std::string	type_;
};

#endif