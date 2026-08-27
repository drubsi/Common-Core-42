#ifndef	BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP
#include <map>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void readFileInput(char** argv);

	private:
		std::map<std::string, double>	database;
		std::string						dateInput;
		double							rateInput;

		void loadDBExchange();
		void validateHeader(const std::string& line);
		void validateInput(const std::string& line);
		void cutPairs(const std::string& line, std::string& dateInput, double& rateInput);
		void convertDate();
		void validateData();
		void comparePair();
};
#endif
