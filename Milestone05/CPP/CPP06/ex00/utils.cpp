#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <climits>

static void printChar(double value)
{
	char character;

	if (value < CHAR_MIN || value > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else
	{
		character = static_cast<char> (value);
		if (isprint(character) == 0)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << "\'" << character << "\'" << std::endl;
	}
}

static void printInt(double value)
{
	int	integer;

	if (value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
	{
		integer = static_cast<int> (value);
		std::cout << "int: " << integer << std::endl;
	}
}

static void printDouble(double value)
{
	double doubleN = static_cast<double>(value);

	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1)  << doubleN << std::endl;
}

static void printFloat(double value)
{
	float	floatN = static_cast<float>(value);

	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << floatN << "f" << std::endl;
}
void printAll(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
void printSpecial(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf")
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
	if (literal == "+inff" || literal == "+inf")
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
	if (literal == "-inf" || literal == "-inff")
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
}

void printInvalid()
{
	std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
}

static void countCharacters(const std::string& literal, char character, int& counter)
{
	for (size_t i = 0; i < literal.length(); i++)
		if (character == literal[i])
			counter++;
}

static int isChar(const std::string& literal)
{
	size_t size = literal.length();

	if (size == 1 && isdigit(literal[0]) == 0 && isprint(literal[0]))
	{
		return (1);
	}
	return (0);
}
static int isFloat(const std::string& literal)
{
	int counterF = 0;
	int	counterDot = 0;
	countCharacters(literal, 'f', counterF);
	countCharacters(literal, '.', counterDot);
	if (counterF == 1 && counterDot == 1)
		return (1);
	return (0);
}

static int isDouble(const std::string& literal)
{
	int	counter = 0;

	countCharacters(literal, '.', counter);
	if (counter == 1)
		return (1);
	return (0);
}

static void readString(const std::string& literal, int& nCharacters, int& invalid)
{
	for (size_t i = 0; i < literal.length(); i++)
	{
		if(isalpha(literal[i]))
			nCharacters++;
		if((literal[i] == 'f' && i + 1 < literal.length()) || (literal[i] == '-' && i > 0 )|| (literal[i] == '+' && i > 0))
		{
			invalid = 1;
			break;
		}
	}
}

static int isInvalid(const std::string& literal)
{
	int sign = 0;
	int dot = 0;
	int fChar = 0;
	int	nCharacters = 0;
	int	invalid = 0;
	
	countCharacters(literal, '+', sign);
	countCharacters(literal, '-', sign);
	countCharacters(literal, 'f', fChar);
	countCharacters(literal, '.', dot);
	readString(literal, nCharacters, invalid);
	if (sign > 1 || fChar > 1 || dot > 1 || (nCharacters > 0 && fChar == 0) || invalid == 1)
		return (1);
	if ((fChar == 1 && dot != 1 && literal.length() <= 3) || (fChar == 1 && dot == 1 && literal.length() <= 2))
		return (1);
	return (0);
}

static int specialTypes(const std::string& literal)
{
	std::string special[6] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};
	for (size_t i = 0; i < 6; i++)
	{
		if(literal.compare(special[i]) == 0)
			return (0);
	}
	return (1);
}
LiteralType getType(const std::string& literal)
{
	if(isChar(literal) == 1)
		return (TYPE_CHAR);
	else if(specialTypes(literal) == 0)
		return (TYPE_SPECIAL);
	else if(isInvalid(literal) == 1)
		return (TYPE_INVALID);
	else if(isFloat(literal) == 1)
		return (TYPE_FLOAT);
	else if(isDouble(literal) == 1)
		return (TYPE_DOUBLE);
	else
		return(TYPE_INT);
}

LiteralType parse(const std::string& literal)
{
	LiteralType	conversorType;
	
	conversorType = getType(literal);
	return (conversorType);
}

double getValue(const std::string& literal, LiteralType conversionType)
{
	double	value;

	if (conversionType == TYPE_CHAR)
		value = literal[0];
	else
		value = strtod(literal.c_str(), NULL);
	return (value);
}
