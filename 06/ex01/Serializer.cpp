#include <iostream>

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer Default Constructor" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	static_cast<void>(src);
	std::cout << "Serializer Copy Constructor" << std::endl;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer Destructor" << std::endl;
}

Serializer	&Serializer::operator=(const Serializer &other)
{
	static_cast<void>(other);
	std::cout << "Serializer Copy Operator" << std::endl;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	address;

	address = reinterpret_cast<uintptr_t>(ptr);
	return address;
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*data;

	data = reinterpret_cast<Data *>(raw);
	return data;
}
