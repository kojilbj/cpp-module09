#include <string>
#include <iostream>
#include "./include/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_index = 0;
	_full = false;
	bzero(_store, sizeof(Contact) * 8);
}

PhoneBook::~PhoneBook(void)
{

}

void	PhoneBook::add(Contact data)
{
	if (_index == 7)
	{
		_full = true;
		_index = 0;
	}
	_store[_index] = data;
	_index++;
}

void	PhoneBook::search(void)
{
	std::string input;
	int	index;

	index =  -1;
	std::cout << "Please enter the number(1 ~ 8) you wanna check." << std::endl;
	while (!(0 < index && index < 9))
	{
		std::cout << "num: ";
		std::getline(std::cin, input);
		index = atoi(input.data());
	}
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nick Name" << "|";
	std::cout << std::endl;
	std::cout << std::right << std::setw(44) << "----------------------------------------" << std::endl;
	if (index > _index && _full == false)
	{
		std::cout << "Not exist" << std::endl;
		return ;
	}
	_store[index - 1].show_info(index);
}
