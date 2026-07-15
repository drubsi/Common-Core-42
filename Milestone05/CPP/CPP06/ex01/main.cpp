#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main()
{
	Data	data;

	data.id = 1;
	data.name = "new player";

	Data	*original = &data;
	uintptr_t raw = Serializer::serialize(original);
	Data*	recovered = Serializer::deserialize(raw);

	std::cout << original << std::endl;
	std::cout << recovered << std::endl;
	if (original == recovered)
	{
		std::cout << "Same address" << std::endl;
		std::cout << "ID: " << recovered->id << std::endl;
		std::cout << "Name: " << recovered->name << std::endl;
	}
	else
		std::cout << "Different addresses" << std::endl;
	return (0);
}