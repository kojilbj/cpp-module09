#include <iostream>
#include <string>
#include <unistd.h>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	random;

	std::srand(std::time(0));
	random = std::rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void	identify(Base *p)
{
	A	*aPtr;
	B	*bPtr;
	C	*cPtr;

	aPtr = dynamic_cast<A*>(p);
	if (aPtr != NULL)
	{
		std::cout << "This is A!!!" << std::endl;
		return ;
	}
	bPtr = dynamic_cast<B*>(p);
	if (bPtr != NULL)
	{
		std::cout << "This is B!!!" << std::endl;
		return ;
	}
	cPtr = dynamic_cast<C*>(p);
	if (cPtr != NULL)
	{
		std::cout << "This is C!!!" << std::endl;
		return ;
	}
	std::cout << "This is Unknown!!!" << std::endl;
	return ;
}

void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		std::cout << "This is A!!! address: " << &a << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		std::cout << "This is B!!! address: " << &b << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		std::cout << "This is C!!! address: " << &c << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}
	return ;
}

int	main(void)
{
	{
		Base	*unknown = generate();
		identify(unknown);
	}
	{
		A	a;
		B	b;
		C	c;

		identify(a);
		identify(b);
		identify(c);
	}
}
