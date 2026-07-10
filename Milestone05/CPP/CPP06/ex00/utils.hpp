#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>

enum LiteralType
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_SPECIAL,
	TYPE_INVALID,
};

double getValue(const std::string& literal, LiteralType conversionType);
LiteralType getType(const std::string& literal);
void printAll(double value);
void printSpecial(const std::string& literal);
void printInvalid();
LiteralType parse(const std::string& literal);

#endif
