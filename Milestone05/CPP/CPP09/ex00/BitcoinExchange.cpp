#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include <cctype>

BitcoinExchange::BitcoinExchange() : dateInput(""), rateInput(0)
{
	loadDBExchange();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
	: database(copy.database), dateInput(copy.dateInput), rateInput(copy.rateInput)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if(this != &other)
	{
		database = other.database;
		dateInput = other.dateInput;
		rateInput = other.rateInput;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}
void BitcoinExchange::readFileInput(char** argv)
{
	std::ifstream	inputFile;
	std::string		line;
	int				index = 0;

	inputFile.open(argv[1], std::ios::in);
	if (!inputFile)
		throw std::invalid_argument("Error: could not open file.");
	while(std::getline(inputFile, line))
	{
		try
		{
			if (index == 0)
			{
				validateHeader(line);
				index++;
				continue;
			}
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
			index++;
			continue;
		}
		try
		{
			validateInput(line);
			cutPairs(line, dateInput, rateInput);
			convertDate();
			validateData();
			comparePair();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		index++;
	}
	inputFile.close();
}

void BitcoinExchange::loadDBExchange()
{
	std::ifstream	dataFile;
	std::string		line;
	double			rate;

	dataFile.open("data.csv", std::ios::in);
	if(!dataFile.is_open())
		throw std::invalid_argument("Error: could not open reference file.");
	while(std::getline(dataFile, line))
	{
		if(line.empty() || !std::isdigit(line[0]))
			continue;
		std::string::size_type separator = line.find(',');
		std::string date = line.substr(0, separator);
		std::string rateText = line.substr(separator + 1);
		std::istringstream converter(rateText);
		converter >> rate;
		database.insert(std::make_pair(date, rate));
	}
	dataFile.close();
}

void BitcoinExchange::validateHeader(const std::string& line)
{
	std::string		header = "date | value";

		if ((line.empty() || line != header))
			throw std::invalid_argument("Error: Wrong header.");
}

void BitcoinExchange::validateInput(const std::string& line)
{
	int		pipe = 0;
	int		dateSeparator = 0;
	int		dot = 0;
	bool	alpha = false;
	std::string::const_iterator it = line.begin();
	std::ostringstream	msg;
	
	for(; it != line.end(); it++)
	{
		if(*it == '|')
			pipe++;
		else if(*it == '-')
			dateSeparator++;
		else if (*it == '.')
			dot++;
		else if(!std::isdigit(*it) && !std::isspace(*it))
		{
			alpha = true;
			break;
		}
	}
	msg << "Error: bad input => " << line;
	if(pipe != 1 || dateSeparator < 2 || dateSeparator > 3 || dot > 1 || alpha == true)
		throw std::invalid_argument(msg.str());
}

void BitcoinExchange::cutPairs(const std::string& line, std::string& dateInput, double& rateInput)
{
	std::string	rateString;
	std::ostringstream msg;
	std::size_t	separator = line.find_first_of("|", 0);
	dateInput = line.substr(0, separator);
	std::size_t space = dateInput.find_first_of(" ", 0);
	char extra;
	
	msg << "Error: bad input => " << line;
	if (space != std::string::npos)
		dateInput.erase(space);
	separator = line.find_last_of("|");
	rateString = line.substr(separator + 1);
	space = rateString.find_first_not_of(" ", 0);
	rateString.erase(0, space);
	std::istringstream converter(rateString);
	converter >> rateInput;
	if (!converter)
		throw (std::invalid_argument(msg.str()));
	converter >> extra;
	if (converter)
		throw (std::invalid_argument(msg.str()));	
}

void BitcoinExchange::convertDate()
{
	std::ostringstream msg;

	msg << "Error: Invalid date => " << dateInput;
	if (dateInput.size() != 10)
		throw std::invalid_argument(msg.str());
	int year;
	int	month;
	int day;
	char separator;
	std::istringstream converter(dateInput);
	converter >> year >> separator >> month >> separator >> day;
	if (year < 1000 || (month < 1 || month > 12) 
		|| (day < 1 || day > 31) || (month == 2 && day > 29))
		throw std::invalid_argument(msg.str());
}
void BitcoinExchange::validateData()
{
	if(rateInput < 0)
		throw std::invalid_argument("Error: not a positive number.");
	else if (rateInput > 1000)
		throw std::invalid_argument("Error: too large a number.");
}

void BitcoinExchange::comparePair()
{
	std::map<std::string, double>::iterator it;
	std::ostringstream msg;

	msg << "Error: The date entered is earlier than the first date in the database => " << dateInput; 
	it = database.upper_bound(dateInput);
	if (it != database.end())
	{
		if (it != database.begin())
			it--;
		else if (it == database.begin())
			throw std::invalid_argument(msg.str());
		std::cout << dateInput << " => " << rateInput << " = "<< (it->second * rateInput) << std::endl;
	}
	else if (it == database.end())
	{
		it--;
		std::cout << dateInput << " => " << rateInput << " = "<< (it->second * rateInput) << std::endl;
	}
}
