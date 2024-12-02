#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string.h>
#include <string>

class PhoneBook
{

public:
	PhoneBook(void);
	~PhoneBook(void);

	void add(Contact data);
	void search(void);

private:
	Contact store_[8];
	int index_;
	bool full_;
};

#endif
