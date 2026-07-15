#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& copy)
{
	(void)copy;
}
Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return(*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* data;

	data = reinterpret_cast<Data*>(raw);
	return (data);
}
