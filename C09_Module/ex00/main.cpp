#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	BitcoinExchange btc;

	if (argc != 2) {
		std::cerr << "Wrong usage! (./btc input.txt)" << std::endl;
		return 0;
	}
	try {
		btc.readDatabase();
		btc.processInput(argv[1]);
	}
	catch (BitcoinExchange::DatabaseException& e) {
		std::cout << e.what() << std::endl;
	}
	//btc.printDB();
	return 0;
}
