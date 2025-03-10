#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(15);
        lst.push_back(25);

        std::list<int>::iterator it = easyfind(lst, 50);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
