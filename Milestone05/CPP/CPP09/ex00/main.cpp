#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>

int	main(int argc, char** argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Error: could not open file.");
		BitcoinExchange	bc;
		bc.readFileInput(argv);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}	
	return (0);
}
