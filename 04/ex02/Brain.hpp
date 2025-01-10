#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class	Brain
{
	public:
		Brain(void);
		Brain(const Brain& src);
		~Brain(void);

		Brain&	operator=(const Brain& src);
	private:
		std::string	ideas[100];
};

#endif