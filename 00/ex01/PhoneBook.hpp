#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP
#include <string>
#include <iostream>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		int	index;

	public:
		Contact	store[8];
		void	add(Contact data);
		void	search();
};

void	PhoneBook::add(Contact data)
{
	if (index == 7)
		index = 0;
	store[index] = data;
	index++;
}

void	PhoneBook::search()
{
	int	i;

	i = 0;
	//std::cout << store[i].first_name;
	//std::cout << std::endl;
	while (store[i].first_name[0] != '\0' && i < 8)
	{
		std::cout << store[i].first_name << "|";
		std::cout << store[i].last_name << "|";
		std::cout << store[i].nickname << "|";
		std::cout << store[i].phone_number << "|";
		std::cout << store[i].darkest_secret;
		std::cout << std::endl;
		i++;
	}
}

#endif
