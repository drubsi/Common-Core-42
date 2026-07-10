#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "To execute the program there must be a literal type parameter. ./convert <parameter>." << std::endl;
		return(1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
