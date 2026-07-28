#include "easyfind.hpp"

const char *NotFound::what() const throw()
{
	return ("Value not found");
}
