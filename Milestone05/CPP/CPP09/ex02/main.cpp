#include "PmergeMe.hpp"

#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <climits>

void validateInput(const std::string& input)
{
	std::size_t qtyNumbers = 0;

	if (input.empty())
		throw std::invalid_argument("Error.");
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (std::isdigit(*it))
			qtyNumbers++;
		else if (!std::isdigit(*it) && !std::isspace(*it))
			throw std::invalid_argument("Error.");
	}
	if (qtyNumbers < 1)
		throw std::invalid_argument("Error.");
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
void validateConversion(const InputData& data)
{
	std::istringstream converter(data.input);
	std::string firstConversion;
	long value = 0;

	while (converter >> firstConversion)
	{
		std::istringstream ValidateConversion(firstConversion);
		ValidateConversion >> value;
		if (!ValidateConversion.eof() || ValidateConversion.fail())
			throw std::invalid_argument("Error.");

		if (value <= 0 || value > INT_MAX)
			throw std::invalid_argument("Error.");
	}
}

void parseAndValidateInput(InputData& data, int argumentCount,
	char** arguments)
{
	initializeInputData(data, argumentCount, arguments);
	validateInput(data.input);
	validateConversion(data);
}

int main(int argc, char** argv)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Error.");
		InputData data;

		parseAndValidateInput(data, argc, argv);
		PmergeMe pmergeMe;

		pmergeMe.processInput(data);
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
		return(1);
	}
	return(0);
}
