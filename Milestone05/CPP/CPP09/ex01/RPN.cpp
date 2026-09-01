#include "RPN.hpp"
#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

RPN::RPN() : n1(0), n2(0), result(0), sign(0)
{
}

RPN::RPN(const RPN& copy)
	: cola(copy.cola), n1(copy.n1), n2(copy.n2), result(copy.result), sign(copy.sign)
{
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->cola = other.cola;
		this->n1 = other.n1;
		this->n2 = other.n2;
		this->sign = other.sign;
		this->result = other.result;
	}
	return (*this);
}

RPN::~RPN()
{
}

void RPN::checkInput(char* argv)
{
	std::string			inputStr = argv;

	if (inputStr.empty())
		throw std::invalid_argument("Error");
	validateInput(inputStr);
}

void RPN::validateInput(const std::string& inputStr)
{
	std::string::const_iterator	it = inputStr.begin();
	int							countDigit = 0;
	int							countSign = 0;

	for (; it != inputStr.end(); it++)
	{
		if (std::isdigit(*it))
			countDigit++;
		else if (isSign(*it))
			countSign++;
		else if (std::isprint(*it) && !std::isspace(*it))
			throw std::invalid_argument("Error");
	}
	if (countDigit < 1 || countSign >= countDigit)
		throw std::invalid_argument("Error");
}

void RPN::readInput(char* argv)
{
	std::string			token;
	std::istringstream	input(argv);

	while (input >> token)
	{
		if (std::isdigit(token.at(0)))
			pushStack(token);
		else if (isSign(token.at(0)))
		{
			sign = token.at(0);
			popStack();
			makeOperation();
		}
	}
	result = cola.top();
	cola.pop();
	if (cola.empty())
		std::cout << result << std::endl;
	else
		throw std::invalid_argument("Error");
}

void RPN::pushStack(const std::string& token)
{
	std::istringstream	converse(token);
	int						temp;

	converse >> temp;
	if (temp > 9)
		throw std::invalid_argument("Error");
	cola.push(temp);
}

void RPN::popStack()
{
	if (cola.size() < 2)
		throw std::invalid_argument("Error");
	n2 = cola.top();
	cola.pop();
	n1 = cola.top();
	cola.pop();
}

void RPN::makeOperation()
{
	if (sign == '+')
		result = n1 + n2;
	else if (sign == '-')
		result = n1 - n2;
	else if (sign == '*')
		result = n1 * n2;
	else if (sign == '/')
	{
		if (n2 == 0)
			throw std::invalid_argument("Error");
		result = n1 / n2;
	}
	cola.push(result);
	sign = 0;
}

bool RPN::isSign(char token)
{
	if (token == '+' || token == '-' || token == '*' || token == '/')
		return (true);
	return (false);
}
