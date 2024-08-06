#include <string>
#include <iostream>
#include "./Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int	main(void)
{
	Zombie	zom("koji");
	zom.announce();
	randomChump("watanabe");
	Zombie	*nw;
	nw = newZombie("kojwatan");
	nw->announce();
	delete nw;
}