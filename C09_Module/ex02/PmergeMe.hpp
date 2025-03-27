#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <ctime>

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
		template <typename T>
		void printContainer(const T& container);
		int Jacobsthal(int k);
		void mergeSortDeque(void);
		void mergeSortList(void);
		std::vector<int> generateJacobsthalNumbers(int limit);
		class MyException: public std::exception {
			public:
				const char* what() const throw();
		};
    private:
        std::deque<int> myDeque;
		std::vector<int> myVector;
};

#endif // PMERGEME_HPP
