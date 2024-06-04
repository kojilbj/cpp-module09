#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	stdin_clear(void)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int	main(void)
{
	PhoneBook book;
	std::string	input;

	book.store[0].first_name = "KOJI";
	book.store[1].first_name = "YUTA";
	while (1)
	{
		std::cout << "PhoneBook prompt >> ";
		std::cin >> input;
		if (input == "ADD")
			std::cout << input << std::endl;
		if (input == "SEARCH")
			book.search();
		if (input == "EXIT")
			std::cout << input << std::endl;
		stdin_clear();
	}
	book.search();
}
