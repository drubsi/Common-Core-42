#include "PmergeMe.hpp"

#include <cctype>
#include <iostream>
#include <stdexcept>

void validateInput(const std::string& input)
{
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it) && !std::isspace(*it))
			throw std::invalid_argument("Error.");
	}
}

void initializeInputData(InputData& data, int argumentCount, char** arguments)
{
	for (int index = 1; index < argumentCount; index++)
	{
		data.input.append(arguments[index]);
		if (index != argumentCount - 1)
			data.input.append(" ");
	}
}

void parseAndValidateInput(InputData& data, int argumentCount,
	char** arguments)
{
	initializeInputData(data, argumentCount, arguments);
	validateInput(data.input);
}

int main(int argc, char** argv)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Error.");
		InputData data;

		parseAndValidateInput(data, argc, argv);
		std::cout << "Before: " << data.input << std::endl;
		PmergeMe pmergeMe(data);
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}
}
