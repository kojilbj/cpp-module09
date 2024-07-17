#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	_store[8];
		int	_index;
		bool	_full;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(Contact data);
		void	search(void);
};

#endif
