#include "./Account.hpp" 
#include <string>
#include <iostream>

int	main(void)
{
	Account	ac(10);

	std::cout << ac.checkAmount() << std::endl;
	return (0);
}