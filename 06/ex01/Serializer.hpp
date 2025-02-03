#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

#include "Data.hpp"

class	Serializer
{
public:
	Serializer(void);
	Serializer(const Serializer &src);

	~Serializer(void);

	Serializer	&operator=(const Serializer &other);

	static uintptr_t	serialize(Data *ptr);
	static Data	*deserialize(uintptr_t raw);

private:
};

#endif
