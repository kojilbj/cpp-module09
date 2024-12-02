#include "./include/Contact.hpp"

Contact::Contact(void)
{
	firstName_ = "";
	lastName_ = "";
	nickName_ = "";
	phoneNumber_ = "";
	darkestSecret_ = "";
}

Contact::~Contact(void) { }

bool Contact::isAllSpace(std::string data) const
{
	int i;

	i = 0;
	while (i < data.length())
	{
		if (data[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool Contact::setInfoUtil(std::string& data)
{
	std::cin.clear();
	std::getline(std::cin, data);
	if (std::cin.eof() == true)
	{
		std::cout << "\nYou entered EOF, this program is terminated." << std::endl;
		exit(EXIT_SUCCESS);
	}
	std::cin.clear();
	if (data.length() == 0 || isAllSpace(data) == true)
		return (false);
	return (true);
}

void Contact::setInfo(void)
{
	std::cout << "first name: ";
	while (setInfoUtil(firstName_) == false)
		std::cout << "first name: ";
	std::cout << "last name: ";
	while (setInfoUtil(lastName_) == false)
		std::cout << "last name: ";
	std::cout << "nick name: ";
	while (setInfoUtil(nickName_) == false)
		std::cout << "nick name: ";
	std::cout << "phone number: ";
	while (setInfoUtil(phoneNumber_) == false)
		std::cout << "phone number: ";
	std::cout << "darkest secret: ";
	while (setInfoUtil(darkestSecret_) == false)
		std::cout << "darkest secret: ";
}

void Contact::showInfo(int index) const
{
	std::cout << std::right << std::setw(10) << index << "|";
	if (firstName_.length() < 10)
		std::cout << std::right << std::setw(10) << firstName_ << "|";
	else
		std::cout << std::right << std::setw(10) << firstName_.substr(0, 9) << ".|";
	if (lastName_.length() < 10)
		std::cout << std::right << std::setw(10) << lastName_ << "|";
	else
		std::cout << std::right << std::setw(10) << lastName_.substr(0, 9) << ".|";
	if (nickName_.length() < 10)
		std::cout << std::right << std::setw(10) << nickName_ << "|";
	else
		std::cout << std::right << std::setw(10) << nickName_.substr(0, 9) << ".|";
	std::cout << std::endl;
}

void Contact::deleteInfo(void)
{
	firstName_.erase(0);
	lastName_.erase(0);
	nickName_.erase(0);
	phoneNumber_.erase(0);
	darkestSecret_.erase(0);
}