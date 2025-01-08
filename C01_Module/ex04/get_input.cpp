#include "get_input.hpp"

Input::Input(std::string filename, std::string s1, std::string s2): _filename(filename), _s1(s1), _s2(s2) {
     if (_s1 == "" || _s2 == "" || _filename == "")
    {
        std::cout << "Arguments can't be empty" << std::endl;
        exit(1);
    }
}

Input::~Input() {};

std::string Input::getFilename(void) {
    return _filename;
}

std::string Input::getS1(void) {
    return _s1;
}

std::string Input::getS2(void) {
    return _s2;
}