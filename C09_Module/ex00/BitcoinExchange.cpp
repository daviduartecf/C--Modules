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
	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		if (!line.empty() && line == "date,exchange_rate") {
			break;
		}
		throw(DatabaseException("Bad format database."));
	}

	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		checkDate(date);
		ss >> price;
		database[date] = price;
	}
}

void BitcoinExchange::checkDate(std::string date) {
	std::string msg= "bad input => ";
	if (date.find('-') == std::string::npos) {
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
	if (year <= 0 || year > 9999) {
		std::string finalMsg = msg += date;
		throw InputException(finalMsg);
	}
	month = atoi(monthS.c_str());
	if (month <= 0 || month > 12) {
		std::string finalMsg = msg += date;
		throw InputException(finalMsg);
	}
	day = atoi(dayS.c_str());
	if (month == 2) {
		if (year % 4 == 0) {
			if (day > 29 || day <= 0) {
				std::string finalMsg = msg += date;
				throw InputException(finalMsg);
			}
		}
		else if (year % 4 != 0) {
			if (day > 28 || day <= 0) {
				std::string finalMsg = msg += date;
				throw InputException(finalMsg);
			}
		}
		else if (year % 4 == 0 && year % 100 == 0) {
			if (day > 28 || day <= 0) {
				std::string finalMsg = msg += date;
				throw InputException(finalMsg);
			}
		}
	}
	if (month == 4 || month == 6 || month == 9
		|| month == 11) {
			if (day > 30 || day <= 0) {
				std::string finalMsg = msg += date;
				throw InputException(finalMsg);
			}
		}
	if (day <= 0 || day > 31) {
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
		throw InputException("Couldn't open input file");
	}

	std::string header;
	std::getline(file, header);
	if (header != "date | value") {
		throw(DatabaseException("Bad format input."));
	}
	std::string line, date, dateS, valueS;
	double value;
	float total;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		if (line.empty())
			continue;
		dateS = ss.str();
		try {
			if (dateS.length() < 14) {
				std::string finalMsg = "bad input => " + dateS;
				throw InputException(finalMsg);
			}
			if (dateS[10] != ' ' || dateS[11] != '|' || dateS[12] != ' ') {
				std::string finalMsg = "bad input => " + dateS;
				throw InputException(finalMsg);
			}
			std::getline(ss, date, '|');
			if (date.length() != 11) {
				std::string finalMsg = "bad input => " + date;
				throw InputException(finalMsg);
			}
			if (date[4] != '-' || date[7] != '-') {
				std::string finalMsg = "bad input => " + date;
				throw InputException(finalMsg);
			}
			checkDate(date);
			std::getline(ss, valueS);

			std::stringstream conv(valueS);
			if (!isValidFloat(valueS)) {
				std::string finalMsg = "bad input => " + valueS;
				throw InputException(finalMsg);
			}
			conv >> value;
			if (conv.fail()) {
				std::string finalMsg = "bad input => " + valueS;
				throw InputException(finalMsg);
			}
			if (value < 0)
				throw InputException("not a positive number.");
			else if (value > 1000 || valueTooHigh(valueS))
				throw InputException("too large a number.");
			total = calculateTotal(value, date);
			std::cout << date << "=> " << value << " = " << total << std::endl;
		}
		catch (BitcoinExchange::InputException& e) {
			std::cout << e.what() << std::endl;
		}
	}
}

bool BitcoinExchange::valueTooHigh(const std::string& valueS) {
	std::stringstream ss(valueS);
	long double val;
	ss >> val;
	if (ss.fail()) return true;
	if (val < 1000.0L)
		return false;
	if (val > 1000.0L)
		return true;

	std::string trimmed = valueS;
	while (!trimmed.empty() && isspace(trimmed[0]))
		trimmed.erase(0, 1);

	size_t dot = trimmed.find('.');
	if (dot == std::string::npos)
		return false;

	std::string decimals = trimmed.substr(dot + 1);
	for (size_t i = 0; i < decimals.size(); ++i) {
		if (decimals[i] != '0')
			return true;
	}
	return false;
}


float	BitcoinExchange::calculateTotal(float value, std::string date) {
	float total;
	std::string newDate = getClosestDate(date);
	total = value * database[getClosestDate(date)];
	return total;
}

std::string BitcoinExchange::getClosestDate(std::string date) {
	std::map<std::string, float>::iterator it = database.lower_bound(date);

	if (it == database.end()) {
		if (database.empty())
		throw InputException("empty database.");
	}
	if (it->first == date)
	return it->first;
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

bool BitcoinExchange::isValidFloat(const std::string& str) {
    if (str.empty())
		return false;
	if (str[1] == '-')
		return true;
    int dotCount = 0;
    for (std::size_t i = 1; i < str.length(); ++i) {
        char c = str[i];
        if (c == '.') {
            ++dotCount;
            if (dotCount > 1) return false;
        } else if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
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
