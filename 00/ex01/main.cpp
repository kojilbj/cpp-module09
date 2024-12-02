#include "./include/Contact.hpp"
#include "./include/PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook book;
	Contact contact;
	std::string input;

	while (std::cin.eof() == false)
	{
		std::cout << "PhoneBook prompt >> ";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			contact.setInfo();
			book.add(contact);
			contact.deleteInfo();
		}
		if (input == "SEARCH")
			book.search();
		if (input == "EXIT")
		{
			std::cout << "Terminate this program." << std::endl;
			break;
		}
	}
	if (std::cin.eof() == true)
		std::cout << "\nYou entered EOF, this program is terminated." << std::endl;
	return (0);
}
