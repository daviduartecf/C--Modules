#include <string>
#include <iostream>

int main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string *p_str = &str;
    std::string &r_str = str;

    std::cout << "Str address: " << &str << std::endl;
    std::cout << "Address that p_str is pointing: " << p_str << std::endl;
    std::cout << "Address that r_str is referencing: " << &r_str << std::endl;

    std::cout << "Str : " << str << std::endl;
    std::cout << "Str pointed by p_str: " << *p_str << std::endl;
    std::cout << "Str referenced by r_str: " << r_str << std::endl;
}