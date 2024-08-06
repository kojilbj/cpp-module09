#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	dt1("koji");
	DiamondTrap	dt2("watanabe");
	DiamondTrap dt3(dt1);
	dt3.whoAmI();
}
