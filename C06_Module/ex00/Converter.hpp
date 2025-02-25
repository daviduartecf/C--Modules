#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter {
private:
    ScalarConverter();  // Private constructor to prevent instantiation
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    static void convert(const std::string& literal);

private:
    static bool isChar(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);
    
    static void printChar(char c);
    static void printInt(int n);
    static void printFloat(float f);
    static void printDouble(double d);
};

#endif
