#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

const BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& other) {
	database = other.database;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	database = other.database;
}

void BitcoinExchange::readDatabase() {
	std::ifstream file("data.csv");
	if (!file) {
		throw(DatabaseException("Couldn't open database file."));
	}

	std::string date, line;
	float price;
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		throw(DatabaseException("Bad format database."));
	}

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		checkDate(date);
		ss >> price;
		database[date] = price;
	}
}

void BitcoinExchange::checkDate(std::string date) {
	if (date.find('-') == std::string::npos) {
		std::string msg = "bad input => ";
		std::string finalMsg = msg += date;
		throw InputException(finalMsg);
	}
	std::stringstream ss(date);
	std::string yearS, monthS, dayS;
	std::getline(ss, yearS, '-');
	std::getline(ss, monthS, '-');
	std::getline(ss, dayS);
	int year, month, day;
	year = atoi(yearS.c_str());
	if (year < 0 || year > INT_MAX) {
		std::string msg = "bad input => ";
		std::string finalMsg = msg += date;
		throw InputException(finalMsg);
	}
	month = atoi(monthS.c_str());
	if (month < 0 || month > 12) {
		std::string msg = "bad input => ";
		std::string finalMsg = msg += date;
		throw InputException(finalMsg);
	}
	day = atoi(dayS.c_str());
	if (day < 0 || day > 31) {
		std::string msg = "bad input => ";
		std::string finalMsg = msg += date;
		throw InputException(finalMsg);
	}
}

void BitcoinExchange::checkInput(std::string inputFile) {
	(void)inputFile;
}

void BitcoinExchange::processInput(std::string inputFile) {
	std::ifstream file(inputFile.c_str());
	if (!file) {
		std::cerr << "Couldn't open database" << std::endl;
		exit(1);
	}
	std::string header;
	std::getline(file, header);
	std::string line, date;
	float value;
	float total;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::getline(ss, date, '|');
		try {
			checkDate(date);
			ss >> value;
			if (value < 0)
				throw InputException("not a positive number.");
			else if (value > 1000)
				throw InputException("too large a number.");
			total = calculateTotal(value, date);
			std::cout << date << " => " << value << " = " << total << std::endl;
		}
		catch (BitcoinExchange::InputException& e) {
			std::cout << e.what() << std::endl;
		}
	}
}

float	BitcoinExchange::calculateTotal(float value, std::string date) {
	float total;
	std::string newDate = getClosestDate(date);
	//std::cout << date << " => " << newDate << std::endl;
	total = value * database[getClosestDate(date)];
	return total;
}

std::string BitcoinExchange::getClosestDate(std::string date) {
	std::map<std::string, float>::iterator it = database.lower_bound(date);

	if (it->first == date)
		return it->first;
	if (it == database.end()) {
		if (database.empty()) //if no greater/equal date exists (can't use --it)
			throw InputException("empty database.");
	}
	if (it == database.begin())
		throw InputException("invalid date (bitcoin not existent)");
	--it;
	return it->first;
}

void BitcoinExchange::printDB() {
	std::map<std::string, float>::iterator it;
	for (it = database.begin(); it != database.end(); ++it) {
		std::cout << it->first << " = " << it->second << std::endl;
	}
}

BitcoinExchange::InputException::InputException(std::string message) {
	std::string errorMsg = "Error: ";
	_message = errorMsg;
	_message += message;
}

BitcoinExchange::InputException::~InputException() throw() {}

const char* BitcoinExchange::InputException::what() const throw() {
    return _message.c_str();
}

BitcoinExchange::DatabaseException::DatabaseException(std::string message) {
	std::string errorMsg = "Error: ";
	_message = errorMsg;
	_message += message;
}

BitcoinExchange::DatabaseException::~DatabaseException() throw() {}

const char* BitcoinExchange::DatabaseException::what() const throw() {
    return _message.c_str();
}
