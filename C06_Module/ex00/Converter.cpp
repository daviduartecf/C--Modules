#include "Converter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    std::cout << std::fixed << std::setprecision(1);

    // Handle special floating-point cases
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
        literal == "-inf" || literal == "+inf" || literal == "nan") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << (literal[literal.size() - 1] != 'f' ? "f" : "") << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }

    // Convert to char
    if (isChar(literal)) {
        char c = literal[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
        return;
    }

    // Convert to int
    if (isInt(literal)) {
        int n = std::atoi(literal.c_str());
        printChar(static_cast<char>(n));
        printInt(n);
        printFloat(static_cast<float>(n));
        printDouble(static_cast<double>(n));
        return;
    }

    // Convert to float
    if (isFloat(literal)) {
        float f = std::atof(literal.c_str());
        printChar(static_cast<char>(f));
        printInt(static_cast<int>(f));
        printFloat(f);
        printDouble(static_cast<double>(f));
        return;
    }

    // Convert to double
    if (isDouble(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        printChar(static_cast<char>(d));
        printInt(static_cast<int>(d));
        printFloat(static_cast<float>(d));
        printDouble(d);
        return;
    }

    std::cout << "Invalid input." << std::endl;
}

bool ScalarConverter::isChar(const std::string& str) {
    return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string& str) {
    for (size_t i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < str.size(); i++) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
    return (str.find('.') != std::string::npos && str[str.size() - 1] == 'f');
}

bool ScalarConverter::isDouble(const std::string& str) {
    return (str.find('.') != std::string::npos && str[str.size() - 1] != 'f');
}

void ScalarConverter::printChar(char c) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int n) {
    std::cout << "int: " << n << std::endl;
}

void ScalarConverter::printFloat(float f) {
    std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: " << d << std::endl;
}
