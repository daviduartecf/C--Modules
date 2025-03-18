#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    std::cout << "Testing with std::vector:" << std::endl;
	std::cout << "Searching 30..." << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Number not found!" << std::endl;
    }

	std::cout << "Searching 100..." << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 100);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Number not found!" << std::endl;
    }

    std::cout << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    lst.push_back(45);

    std::cout << "Testing with std::list:" << std::endl;
	std::cout << "Searching 15..." << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Number not found!" << std::endl;
    }

	std::cout << "Searching 60..." << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst, 60);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Number not found!" << std::endl;
    }

    std::cout << std::endl;

    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);

    std::cout << "Testing with std::deque:" << std::endl;
	std::cout << "Searching 200..." << std::endl;
    try {
        std::deque<int>::iterator it = easyfind(deq, 200);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Number not found!" << std::endl;
    }

	std::cout << "Searching 500..." << std::endl;
    try {
        std::deque<int>::iterator it = easyfind(deq, 500);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Number not found!" << std::endl;
    }

    return 0;
}

