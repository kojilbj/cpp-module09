#include "./include/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	index_ = 0;
	full_ = false;
	bzero(store_, sizeof(Contact) * 8);
}

PhoneBook::~PhoneBook(void) { }

void PhoneBook::add(Contact data)
{
	if (index_ == 8)
	{
		full_ = true;
		index_ = 0;
	}
	std::cout << "This contact is restored in " << index_ + 1 << "." << std::endl;
	store_[index_] = data;
	index_++;
}

void PhoneBook::search(void)
{
	std::string input;
	int index;

	index = -1;
	std::cout << "Please enter the number(1 ~ 8) you wanna check." << std::endl;
	while (!(0 < index && index < 9))
	{
		std::cout << "num: ";
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "\nYou entered EOF, this program is terminated." << std::endl;
			exit(EXIT_SUCCESS);
		}
		index = atoi(input.data());
	}
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nick Name" << "|";
	std::cout << std::endl;
	std::cout << std::right << std::setw(44) << "----------------------------------------"
			  << std::endl;
	if (index > index_ && full_ == false)
	{
		std::cout << "Not exist" << std::endl;
		return;
	}
	store_[index - 1].showInfo(index);
}
