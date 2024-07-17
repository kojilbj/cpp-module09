#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>
#include <iomanip>

class	Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

		bool	_is_all_space(std::string data) const;
		bool	_set_info_util(std::string &data);

	public:
		Contact(void);
		~Contact(void);

		void	set_info(void);
		void	show_info(int index) const;
		void	delete_info(void);
};

#endif
