#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iomanip>
#include <iostream>
#include <string>

class Contact
{
public:
	Contact(void);
	~Contact(void);

	void setInfo(void);
	void showInfo(int index) const;
	void deleteInfo(void);

private:
	std::string firstName_;
	std::string lastName_;
	std::string nickName_;
	std::string phoneNumber_;
	std::string darkestSecret_;

	bool isAllSpace(std::string data) const;
	bool setInfoUtil(std::string& data);
};

#endif
