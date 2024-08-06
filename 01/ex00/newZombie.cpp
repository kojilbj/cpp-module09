#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*onew;

	onew = new Zombie(name);
	return (onew);
}
