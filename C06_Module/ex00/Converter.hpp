#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <cfloat>
#include <cmath>
#include <cctype>
#include <cstdio>

class ScalarConverter {
	private:
		ScalarConverter();  // Private constructor to prevent instantiation
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(const std::string& literal);
};

bool isChar(const std::string& str);
bool isInt(const std::string& str);
bool isFloat(const std::string& str);
bool isDouble(const std::string& str);

void printChar(char c);
void printInt(int n);
void printFloat(float f);
void printDouble(double d);

#endif
