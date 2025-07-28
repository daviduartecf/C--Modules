#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <algorithm>
# include <iterator>
# include <map>
# include <sstream>
# include <climits>
# include <cfloat>
# include <exception>

class BitcoinExchange
{
	public:
		//ORTHODOX CANONICAL FORM
		BitcoinExchange();
		~BitcoinExchange();
		const BitcoinExchange& operator = (const BitcoinExchange& other);
		BitcoinExchange(const BitcoinExchange& other);
		//METHODS
		void readDatabase();
		void checkDate(std::string date);
		void printDB();
		void checkInput(std::string inputFile);
		void processInput(std::string inputFile);
		bool isValidFloat(const std::string& str);
		float calculateTotal(float value, std::string date);
		std::string getClosestDate(std::string date);
		bool valueTooHigh(const std::string& valueS);
		class InputException: public std::exception {
			public:
				explicit InputException(std::string message);
				virtual const char* what() const throw();
				virtual ~InputException() throw();
			private:
				std::string _message;
		};
		class DatabaseException: public std::exception {
			public:
				explicit DatabaseException(std::string message);
				virtual const char* what() const throw();
				virtual ~DatabaseException() throw();
			private:
				std::string _message;
		};
	private:
		std::map<std::string, float> database;
};

#endif
