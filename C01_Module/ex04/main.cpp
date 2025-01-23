#include <iostream>
#include <string>
#include <fstream>
#include "get_input.hpp"

int main(int argc, char *argv[]) {
    if (argc != 4)
    {
        std::cout << "Correct usage: ./sed <filename> \"s1\" \"s2\"" << std::endl;
        return (1);
    }
    Input input(argv[1], argv[2], argv[3]);

    std::ifstream inputFile(input.getFilename().c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }

	std::string replaceFile = input.getFilename() + ".replace";
    std::ofstream outputFile(replaceFile.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file." << std::endl;
        return 1;
    }

    std::string line;
    size_t pos;
    while (std::getline(inputFile, line)) {
        while ((pos = line.find(input.getS1())) != std::string::npos) {
            line.erase(pos, input.getS1().length());
            line.insert(pos, input.getS2());
        }
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
