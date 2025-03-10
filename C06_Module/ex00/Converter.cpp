#include "Converter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    std::cout << std::fixed << std::setprecision(1);

    if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
        literal == "-inf" || literal == "+inf" || literal == "nan") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << (literal[literal.size() - 1] != 'f' ? "f" : "") << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }

    if (isChar(literal)) {
        char c = literal[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
        return;
    }

    if (isInt(literal)) {
        long num;

		if (std::sscanf(literal.c_str(), "%ld", &num) != 1) {
            std::cout << "int: impossible (invalid input)" << std::endl;
            return;
        }
		if (num > INT_MAX || num < INT_MIN) {
            std::cout << "int: impossible (out of int range)" << std::endl;
            return;
        }
        int n = static_cast<int>(num);
        printChar(static_cast<char>(n));
        printInt(n);
        printFloat(static_cast<float>(n));
        printDouble(static_cast<double>(n));
        return;
    }

    if (isFloat(literal)) {
        float f = std::atof(literal.c_str());
		if (f > FLT_MAX) {
            std::cout << "float: impossible (out of range)" << std::endl;
            return;
        }
        printChar(static_cast<char>(f));
		if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
			std::cout << "int: impossible (out of range)" << std::endl;
		else
        	printInt(static_cast<int>(f));
        printFloat(f);
        printDouble(static_cast<double>(f));
        return;
    }

    if (isDouble(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
		if (d > DBL_MAX) {
            std::cout << "double: impossible (out of range)" << std::endl;
            return;
        }
        printChar(static_cast<char>(d));
		if (d > INT_MAX || d < INT_MIN)
			std::cout << "int: impossible (out of range)" << std::endl;
		else
        	printInt(static_cast<int>(d));
        printFloat(static_cast<float>(d));
        printDouble(d);
        return;
    }
    std::cout << "Invalid input." << std::endl;
}

bool isChar(const std::string& str) {
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
    	return true;
	return false;
}


bool isInt(const std::string& str) {
    size_t i;
    if (str[0] == '-' || str[0] == '+')
        i = 1;
    else
        i = 0;
    for (size_t j = i; j < str.size(); j++) {
        if (!std::isdigit(str[j]))
			return false;
    }
    return true;
}

bool isFloat(const std::string& str) {
	int dot_count = 0;
	if (str.find('.') != std::string::npos && str[str.size() - 1] == 'f') {
		size_t l;
		if (str[0] == '-' || str[0] == '+')
			l = 1;
		else
			l = 0;
		for (unsigned int i = l; i < (str.size() - 1); i++) {
			if (!isdigit(str[i]) && str[i] != '.') {
				return false;
			}
		}
		for (unsigned int j = 0; j < str.size(); j++) {
			if (str[j] == '.')
				dot_count++;
		}
		if (dot_count > 1)
			return false;
		return true;
	}
	return false;
}

bool isDouble(const std::string& str) {
	int dot_count = 0;
	if (str.find('.') != std::string::npos) {
		size_t l;
		if (str[0] == '-' || str[0] == '+')
			l = 1;
		else
			l = 0;
		for (unsigned int i = l; i < str.size(); i ++) {
			if (!isdigit(str[i]) && str[i] != '.')
				return false;
			if (str[i] == '.')
				dot_count++;
		}
		if (dot_count == 1)
			return true;
	}
	return false;
}

void printChar(char c) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void printInt(int n) {
	if ((n > INT_MAX || n < INT_MIN))
		std::cout << "int: impossible (out of range)" << std::endl;
	else
    	std::cout << "int: " << n << std::endl;
}

void printFloat(float f) {
	if (f > FLT_MAX)
		std::cout << "float: impossible (out of range)" << std::endl;
	else
    	std::cout << "float: " << f << "f" << std::endl;
}

void printDouble(double d) {
	if (d > DBL_MAX)
		std::cout << "double: impossible (out of range)" << std::endl;
	else
    	std::cout << "double: " << d << std::endl;
}
