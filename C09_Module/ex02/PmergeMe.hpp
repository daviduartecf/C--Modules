#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>
#include <climits>
#include <cmath>
#include <sys/time.h>
#include <cstdlib>
#include <cctype>

class PmergeMe
{
private:
    std::vector<int> myVector;
    std::deque<int> myDeque;
    size_t size;
public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(char *input[], int argc);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

	//template functions
	template <typename T>
    void insertPairs(T& pairs, std::pair<int, int> temp, int index);
    template <typename T>
    void sortPairs(T& pairs, int index);
    template <typename T>
    void printContainer(const T& container);

	//sort and helper functions
    void sortVector();
    void sortDeque();
    bool isValidNumber(std::string token);
    long Jacobsthal(int i);
    std::vector<int> JacobSequenceVector(int size);
	std::deque<int> JacobSequenceDeque(int size);

    // Exception class
    class MyException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif
