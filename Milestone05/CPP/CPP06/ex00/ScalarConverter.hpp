#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& _copy);
		ScalarConverter& operator=(const ScalarConverter& _other);
		~ScalarConverter();

	public:
		static void convert(const std::string& literal);
};

#endif