#include <iostream>

#include "Serializer.hpp"

int	main(void)
{
	Data	data;

	data.key = "userName";
	data.value = "kojwatan";
	uintptr_t	address = Serializer::serialize(&data);
	std::cout << "address: " << address << std::endl;

	Data	*dataAddress;
	dataAddress = Serializer::deserialize(address);
	std::cout << "Data key: " << dataAddress->key << ", value: " << dataAddress->value << std::endl;

	
	return 0;
}
