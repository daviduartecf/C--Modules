#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator = (const PmergeMe& other) {
    if (this != &other)
    {
        this->myDeque = other.myDeque;
		this->myVector = other.myVector;
    }
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    this->myDeque = other.myDeque;
	this->myVector = other.myVector;
}

PmergeMe::PmergeMe(char *input[], int argc) {
	for (int i = 1; i < argc; i ++) {
		std::string str(input[i]);
		if (!isValidNumber(str)) {
			throw MyException();
		}
		int num = std::atoi(str.c_str());
		myDeque.insert(myDeque.end(), num);
		myVector.insert(myVector.end(), num);
	}
	std::cout << "Before: ";
	printContainer(myDeque);

	clock_t startDeque = clock();
	mergeSortDeque();
	std::cout << "After: ";
	printContainer(myDeque);
	clock_t endDeque = clock();
	double timeDeque = static_cast<double>(endDeque - startDeque);
	std::cout << "Time to process a range of " << myDeque.size() << " elements with std::deque container: " << timeDeque << " us" << std::endl;

	clock_t startList = clock();
	//mergeSortList();
	clock_t endList = clock();
	double timeList = static_cast<double>(endList - startList);
	std::cout << "Time to process a range of " << myDeque.size() << " elements with std::deque container: " << timeList << " us" << std::endl;
}

void PmergeMe::mergeSortDeque(void) {
	std::deque<int> auxiliarDeque;
	std::deque<int>::iterator it = myDeque.begin();

    while (it != myDeque.end()) {
        std::deque<int>::iterator nextIt = it;
        ++nextIt;

        if (nextIt != myDeque.end()) {
            if (*it > *nextIt) {
                int temp = *it;
                *it = *nextIt;
                *nextIt = temp;
            }
        }
        auxiliarDeque.push_back(*it);
        it = myDeque.erase(it);
    }
	std::cout << "Auxiliar Deque: ";
	printContainer(auxiliarDeque);
	std::cout << "MyDeque: ";
	printContainer(myDeque);
	std::vector<int> jacobsthalNumbers = generateJacobsthalNumbers(auxiliarDeque.size());
	for (it = myDeque.begin(); it != myDeque.end(); ++it) {
        int low = 0;
        int high = auxiliarDeque.size() - 1;

        for (int i = jacobsthalNumbers.size() - 1; i >= 0; --i) {
            int jump = jacobsthalNumbers[i];
            int mid = low + jump;

            if (mid <= high && auxiliarDeque[mid] <= *it) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        auxiliarDeque.insert(auxiliarDeque.begin() + low, *it);
    }
	//printContainer(auxiliarDeque);
}

std::vector<int> PmergeMe::generateJacobsthalNumbers(int limit) {
    std::vector<int> jacobsthalNumbers;
    jacobsthalNumbers.push_back(0);
    jacobsthalNumbers.push_back(1);

    int i = 2;
    while (true) {
        int nextNumber = jacobsthalNumbers[i - 1] + 2 * jacobsthalNumbers[i - 2];
        if (nextNumber > limit)
			break;
        jacobsthalNumbers.push_back(nextNumber);
        i++;
    }

    return jacobsthalNumbers;
}

void PmergeMe::mergeSortList(void) {

}

bool PmergeMe::isValidNumber(std::string token) {
	long long num;
	std::stringstream ss(token);
	ss >> num;

	if (ss.fail() || !ss.eof()) { // Check for conversion errors
		std::cerr << "Conversion error: " << token << std::endl;
		return false;
	}

	if (num > INT_MAX || num < 0) {
		std::cerr << "Error: Number out of range" << std::endl;
		return false;
	}
	return true;
}

template <typename T>
void PmergeMe::printContainer(const T& container) {
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout  << std::endl;
}

int PmergeMe::Jacobsthal(int k) {
    return round((pow(2, k + 1) + pow(-1, k)) / 3);
}

const char* PmergeMe::MyException::what() const throw() {
	return "Error";
}
