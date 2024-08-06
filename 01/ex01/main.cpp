#include <string>
#include <iostream>
#include "./Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie	*horde;
	horde = zombieHorde(3, "koji");
	std::cout << "--------------" << std::endl;
	int	i = 0;
	while (i < 3)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
}