#include "Harl.hpp"

int	main(int ac, char *av[])
{
	Harl	hrl;

	if (ac != 2)
		return (1);
	hrl.complain(av[1]);
	return (0);
}