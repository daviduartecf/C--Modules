#ifndef GET_INPUT_HPP
#define GET_INPUT_HPP

#include <iostream>
#include <string>
#include "get_input.hpp"

class Input
{
    public:
        Input(std::string filename, std::string s1, std::string s2);
        ~Input();
        std::string getFilename(void);
        std::string getS1(void);
        std::string getS2(void);
    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;
};

#endif