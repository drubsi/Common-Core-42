#include "RPN.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Error");
		RPN	rpn;
		
		rpn.checkInput(argv[1]);
		rpn.readInput(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
