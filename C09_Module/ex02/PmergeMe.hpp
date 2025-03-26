#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <climits>
#include <string>

class PmergeMe {
    public:
		//ORTHODOX CANONICAL FORM
        PmergeMe();
		PmergeMe(char *input[], int argc);
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator = (const PmergeMe& other);
		//METHODS
		bool isValidNumber(std::string token);
    private:
        std::deque<int> myDeque;
		std::vector<int> myVector;
};

#endif // PMERGEME_HPP
