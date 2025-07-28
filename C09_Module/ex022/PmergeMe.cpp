#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : size(0) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->myDeque = other.myDeque;
        this->myVector = other.myVector;
        this->originalNumbers = other.originalNumbers;
        this->size = other.size;
    }
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    this->myDeque = other.myDeque;
    this->myVector = other.myVector;
    this->originalNumbers = other.originalNumbers;
    this->size = other.size;
}

PmergeMe::PmergeMe(char *input[], int argc) : size(0) {
    for (int i = 1; i < argc; i++) {
        std::string str(input[i]);
        if (!isValidNumber(str)) {
            throw MyException();
        }
        int num = std::atoi(str.c_str());
        myDeque.push_back(num);
        myVector.push_back(num);
        originalNumbers.push_back(num);
        size++;
    }
    std::cout << "Vector --------------" << std::endl;
	std::cout << "Before: ";
	printContainer(myVector);
	sortVector();
	std::cout << "After: ";
	printContainer(myVector);
	std::cout << "Deque --------------" << std::endl;
	std::cout << "Before: ";
	printContainer(myDeque);
	sortDeque();
	std::cout << "After: ";
	printContainer(myDeque);
}

template <typename T>
void PmergeMe::insertPairs(T& pairs, std::pair<int, int> temp, int index) {
    // Base case (insert at beginning)
    if (index < 0) {
        pairs.insert(pairs.begin(), temp);
        return;
    }
    // Insert after current index
    if (pairs[index].first < temp.first) {
        pairs.insert(pairs.begin() + (index + 1), temp);
        return;
    }
    // Recursion (keep checking earlier positions)
    insertPairs(pairs, temp, index - 1);
}

template <typename T>
void PmergeMe::sortVectorPairs(T& pairs, int index) {
    std::pair<int, int> temp = pairs[index];
    // Base case
    if (index < 1)
        return;
    // Recursion
    sortVectorPairs(pairs, index - 1);
    temp = pairs[index];
    pairs.erase(pairs.begin() + index);
    insertPairs(pairs, temp, index - 1);
}

long PmergeMe::Jacobsthal(int i) {
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;
    return round((pow(2, i + 1) - pow(-1, i)) / 3);
}

std::vector<int> PmergeMe::JacobSequence(int size) {
    std::vector<int> result;
    int max_index = 1;
    
    // Find appropriate Jacobsthal index
    while (Jacobsthal(max_index) < size)
        max_index++;
    
    for (int i = 1; i < max_index; i++) {
        int curr = Jacobsthal(i + 1);
        if (curr > size)
            curr = size;
        
        // Add numbers in descending order from curr to previous Jacobsthal + 1
        while (curr > Jacobsthal(i)) {
            result.push_back(curr);
            curr--;
        }
    }
    return result;
}

void PmergeMe::sortVector() {
    int lastNumber = -1;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Work with a copy to avoid modifying the original size
    std::vector<int> workVector = myVector;
    size_t workSize = workVector.size();
    bool isOdd = (workSize % 2 != 0);
    
    if (isOdd) {
        lastNumber = workVector.back();
        workVector.pop_back();
    }
    
    // Create pairs
    std::vector<std::pair<int, int> > myPairs;
    for (std::vector<int>::iterator it = workVector.begin(); it != workVector.end(); it += 2)
        myPairs.push_back(std::make_pair(*it, *(it + 1)));

    // Sort each pair (larger first)
    for (std::vector<std::pair<int, int> >::iterator itpair = myPairs.begin(); itpair != myPairs.end(); itpair++) {
        if (itpair->first < itpair->second)
            std::swap(itpair->first, itpair->second);
    }
    
    // Sort all pairs by their larger elements
    if (myPairs.size() > 1)
        sortVectorPairs(myPairs, myPairs.size() - 1);

    // Create 2 sequences -> main and secondSeq
    std::vector<int> main;
    std::vector<int> secondSeq;
    
    // Add first smaller element to main
    if (!myPairs.empty())
        main.push_back(myPairs[0].second);
    
    // Add all larger elements to main
    for (size_t i = 0; i < myPairs.size(); i++)
        main.push_back(myPairs[i].first);
    
    // Add remaining smaller elements to secondSeq
    for (size_t j = 1; j < myPairs.size(); j++)
        secondSeq.push_back(myPairs[j].second);
    
    // Add odd element if exists
    if (isOdd)
        secondSeq.push_back(lastNumber);

    // Insert using Jacobsthal sequence (binary search)
    if (!secondSeq.empty()) {
        std::vector<int> JacobSeq = JacobSequence(secondSeq.size());
        for (size_t i = 0; i < JacobSeq.size(); i++) {
            size_t secondIndex = JacobSeq[i] - 1;
            if (secondIndex < secondSeq.size()) {
                int insertNumber = secondSeq[secondIndex];
                // Get the insert position using upper_bound
                std::vector<int>::iterator it = std::upper_bound(main.begin(), main.end(), insertNumber);
                main.insert(it, insertNumber);
            }
        }
    }
    
    myVector = main;
    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - start.tv_sec) * 1000000.0;
    elapsed += (end.tv_usec - start.tv_usec);
    std::cout << "Time to process a range of " << size
              << " elements with std::vector: " << elapsed << " us" << std::endl;
}

void PmergeMe::sortDeque() {
    int lastNumber = -1;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Work with a copy to avoid modifying the original
    std::deque<int> workDeque = myDeque;
    size_t workSize = workDeque.size();
    bool isOdd = (workSize % 2 != 0);
    
    if (isOdd) {
        lastNumber = workDeque.back();
        workDeque.pop_back();
    }
    
    // Create pairs (using vector for pairs to maintain consistency with sortVectorPairs)
    std::vector<std::pair<int, int> > myPairs;
    for (std::deque<int>::iterator it = workDeque.begin(); it != workDeque.end(); it += 2)
        myPairs.push_back(std::make_pair(*it, *(it + 1)));

    // Sort each pair (larger first)
    for (std::vector<std::pair<int, int> >::iterator itpair = myPairs.begin(); itpair != myPairs.end(); itpair++) {
        if (itpair->first < itpair->second)
            std::swap(itpair->first, itpair->second);
    }
    
    // Sort all pairs by their larger elements
    if (myPairs.size() > 1)
        sortVectorPairs(myPairs, myPairs.size() - 1);

    // Create 2 sequences -> main and secondSeq
    std::deque<int> main;
    std::deque<int> secondSeq;
    
    // Add first smaller element to main
    if (!myPairs.empty())
        main.push_back(myPairs[0].second);
    
    // Add all larger elements to main
    for (size_t i = 0; i < myPairs.size(); i++)
        main.push_back(myPairs[i].first);
    
    // Add remaining smaller elements to secondSeq
    for (size_t j = 1; j < myPairs.size(); j++)
        secondSeq.push_back(myPairs[j].second);
    
    // Add odd element if exists
    if (isOdd)
        secondSeq.push_back(lastNumber);

    // Insert using Jacobsthal sequence (binary search)
    if (!secondSeq.empty()) {
        std::vector<int> JacobSeq = JacobSequence(secondSeq.size());
        for (size_t i = 0; i < JacobSeq.size(); i++) {
            size_t secondIndex = JacobSeq[i] - 1;
            if (secondIndex < secondSeq.size()) {
                int insertNumber = secondSeq[secondIndex];
                // Get the insert position using upper_bound
                std::deque<int>::iterator it = std::upper_bound(main.begin(), main.end(), insertNumber);
                main.insert(it, insertNumber);
            }
        }
    }
    
    myDeque = main;
    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - start.tv_sec) * 1000000.0;
    elapsed += (end.tv_usec - start.tv_usec);
    std::cout << "Time to process a range of " << size
              << " elements with std::deque: " << elapsed << " us" << std::endl;
}

bool PmergeMe::isValidNumber(std::string token) {
    if (token.empty())
        return false;
        
    // Check for leading zeros (except "0" itself)
    if (token.length() > 1 && token[0] == '0')
        return false;
    
    // Check all characters are digits
    for (size_t i = 0; i < token.length(); i++) {
        if (!std::isdigit(token[i]))
            return false;
    }
    
    // Check range
    long long num;
    std::stringstream ss(token);
    ss >> num;

    if (ss.fail() || !ss.eof()) {
        return false;
    }

    if (num > INT_MAX || num < 0) {
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
    std::cout << std::endl;
}

const char* PmergeMe::MyException::what() const throw() {
    return "Error";
}