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
    std::cout << "Input: " << input.getFilename() << ", " << input.getS1() << ", " << input.getS2() << std::endl;

    std::ifstream inputFile(input.getFilename());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }

    std::ofstream outputFile(input.getFilename() + ".replace");
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
        std::cout << line << std::endl;
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}