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
    std::vector<int> originalNumbers;
    size_t size;

    // Helper functions for sorting pairs
    template <typename T>
    void insertPairs(T& pairs, std::pair<int, int> temp, int index);
    
    template <typename T>
    void sortVectorPairs(T& pairs, int index);
    
    // Main sorting functions
    void sortVector();
    void sortDeque();
    
    // Utility functions
    bool isValidNumber(std::string token);
    long Jacobsthal(int i);
    std::vector<int> JacobSequence(int size);
    
    // Template function for printing
    template <typename T>
    void printContainer(const T& container);

public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(char *input[], int argc);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    // Exception class
    class MyException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif
