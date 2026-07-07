#include "ScalarConverter.hpp"


enum LiteralType
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_SPECIAL,
	TYPE_INVALID
};

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
static double getValue(const std::string& literal, LiteralType conversionType)
{
	double	value;

	if (conversionType == TYPE_CHAR)
		value = literal[0];
	else if (conversionType == TYPE_INT)
		value = strtol(literal.c_str(), NULL, 10);
	else if (conversionType == TYPE_FLOAT)
		value = strtof(literal.c_str(), NULL);
	else if (conversionType == TYPE_DOUBLE)
		value = strtod(literal.c_str(), NULL);
	return (value);
}

static LiteralType getType(const std::string& literal)
{
	int	dot = 0;

	if (literal.length() == 1 && isdigit(literal[0])== 0)
		return (TYPE_CHAR);
	for(size_t	i = 0; i < literal.length(); i++)
	{
		if(literal[0] == '+' || literal[0] == '-')
			continue;
		if (literal[i] == '.' && dot == 0)
			dot = 1;
		if(literal[i] == 'f' && dot == 1)
			return (TYPE_FLOAT);
	}
	if (dot == 1)
		return (TYPE_DOUBLE);
	else
		return (TYPE_INT);
}
void printChar(double value)
{
	char character = static_cast<char> (value);

	std::cout << "char: ";
	if (isprint(character))
		std::cout << character << std::endl;
	else
		std::cout << "Non Displayable" << std::endl; 
}

void printInt(double value)
{
	int	integer = static_cast<int> (value);
	std::cout << "int: ";
	std::cout << integer << std::endl;
}

void printDouble(double value)
{
	double doubleN = static_cast<double>(value);

	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1)  << doubleN << std::endl;
}

void printFloat(double value)
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

static LiteralType parse(const std::string& literal)
{
	LiteralType	conversorType;
	
	conversorType = getType(literal);
	return (conversorType);
}

void ScalarConverter::convert(const std::string& literal)
{
	LiteralType		conversorType;
	double			value;
	
	conversorType = parse(literal);
	value = getValue(literal, conversorType);
	printAll(value);

}
