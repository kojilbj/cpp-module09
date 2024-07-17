#include "./include/Contact.hpp"

Contact::Contact(void)
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";
}

Contact::~Contact(void)
{

}

bool	Contact::_is_all_space(std::string data) const
{
	int	i;

	i = 0;
	while (i < data.length())
	{
		if (data[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	Contact::_set_info_util(std::string &data)
{
	std::cin.clear();
	std::getline(std::cin, data);
	if (std::cin.eof() == true)
	{
		std::cout << "\nYou enter EOF, this program is terminated." << std::endl;
		exit (EXIT_SUCCESS);
	}
	std::cin.clear();
	if (data.length() == 0 || _is_all_space(data) == true)
		return (false);
	return (true);
}

void	Contact::set_info(void)
{
	std::cout << "first name: ";
	while (_set_info_util(_first_name) == false)
		std::cout << "first name: ";
	std::cout << "last name: ";
	while (_set_info_util(_last_name) == false)
		std::cout << "last name: ";
	std::cout << "nick name: ";
	while (_set_info_util(_nickname) == false)
		std::cout << "nick name: ";
	std::cout << "phone number: ";
	while (_set_info_util(_phone_number) == false)
		std::cout << "phone number: ";
	std::cout << "darkest secret: ";
	while (_set_info_util(_darkest_secret) == false)
		std::cout << "darkest secret: ";
}

void	Contact::show_info(int index) const
{
	std::cout << std::right << std::setw(10) << index << "|";
	if (_first_name.length() < 10)
		std::cout << std::right << std::setw(10) << _first_name << "|";
	else
		std::cout << std::right << std::setw(10) << _first_name.substr(0, 9) << ".|";
	if (_last_name.length() < 10)	
		std::cout << std::right << std::setw(10) << _last_name << "|";
	else
		std::cout << std::right << std::setw(10) << _last_name.substr(0, 9) << ".|";
	if (_nickname.length() < 10)
		std::cout << std::right << std::setw(10) << _nickname << "|";
	else
		std::cout << std::right << std::setw(10) << _nickname.substr(0, 9) << ".|";
	std::cout << std::endl;
}

void	Contact::delete_info(void)
{
	_first_name.erase(0);
	_last_name.erase(0);
	_nickname.erase(0);
	_phone_number.erase(0);
	_darkest_secret.erase(0);
}
