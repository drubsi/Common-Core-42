#include "ScalarConverter.hpp"
#include "utils.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& _copy)
{
	(void)_copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& _other)
{
	(void)_other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string& literal)
{
	LiteralType		conversorType;
	double			value;
	
		conversorType = parse(literal);
		if (conversorType == TYPE_SPECIAL)
			printSpecial(literal);
		else if (conversorType == TYPE_INVALID)
			printInvalid();
		else
		{
			value = getValue(literal, conversorType);
			printAll(value);
		}
}
