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
		int num = std::atoi(str.c_str());\
		myDeque.push_back(num);
		myVector.push_back(num);
		originalNumbers.push_back(num);
		size ++;
	}
	std::cout << "Before: ";
	printContainer(myVector);
	sortVector(myVector);
	std::cout << "After: ";
	printContainer(myVector);
}
template <typename T>
void insertPairs(T& pairs, std::pair<int, int>temp, int index) {
	//Base case (insert at beggining)
	if (index < 0)
		pairs.insert(pairs.begin(), temp);
	//Insert after current index
	else if (pairs[index].first < temp.first)
		pairs.insert(pairs.begin() + (index + 1), temp);
	//Recursion (keep checking early positions)
	else
		insertPairs(pairs, temp, index - 1);
}

//Sort pairs in descending order
//Recursively sort pairs
//      pairs = { {10, 1}, {7, 2}, {5, 3}, {8, 9} }  -> >> > 8,9 out of order
//		pairs = { {10, 1}, {8, 9}, {7, 2}, {5, 3} }
template <typename T>
void sortVectorPairs(T& pairs, int index) {
	std::pair<int, int> temp = pairs[index];
	//Base case
	if (index < 1)
		return;
	//Recursion
	sortVectorPairs(pairs, index - 1);
	temp = pairs[index];
	pairs.erase(pairs.begin() + index);
	insertPairs(pairs, temp, index - 1);
}

long Jacobsthal(int i) {
	if (i == 0)
		return 0;
	if (i == 1)
		return 1;
	return round((pow(2, i + 1) - pow(-1, i)) / 3);}

std::vector<int> JacobSequence(int size) {
	std::vector<int> result;
	int max_index = 0;
	while (size > Jacobsthal(max_index))
		max_index++;
	for (int i = 0; i < max_index; i++) {
		int curr = Jacobsthal(i + 1);
		if (size < curr)
			curr = size;

		while(curr > Jacobsthal(i)) {
			result.push_back(curr--);
			if (curr <= 0)
				break;
		}
	}
	return result;
}
template <typename T>
void PmergeMe::sortVector(T& vec) {
    int lastNumber = -1;
	struct timeval start, end;
    gettimeofday(&start, NULL);

	//Check if the size if odd and keep the last number if it is
	bool isOdd;
	if (size % 2)
		isOdd = true;
	else
		isOdd = false;
	if (isOdd) {
		lastNumber = myVector.back();
		myVector.pop_back();
	}
	//Create pairs
	std::vector<std::pair<int, int> > myPairs;
	for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it += 2)
		myPairs.push_back(std::make_pair(*it, *(it + 1)));

	//Sort each pair
	for (std::vector<std::pair<int, int> >::iterator itpair = myPairs.begin(); itpair != myPairs.end(); itpair++) {
		if (itpair->first < itpair->second)
			std::swap(itpair->first, itpair->second);
	}
	//Sort all pairs
	sortVectorPairs(myPairs, myPairs.size() - 1);

	//Create 2 sequences -> main and secondSeq
	std::vector<int> main;
	std::vector<int> secondSeq;
	main.push_back(myPairs[0].second);
	for (size_t i = 0; i < myPairs.size(); i ++)
		main.push_back(myPairs[i].first);
	for (size_t j = 1; j < myPairs.size(); j ++)
		secondSeq.push_back(myPairs[j].second);
	if (isOdd)
		secondSeq.push_back(lastNumber);

	//Insert (binary search)
	std::vector<int> JacobSeq = JacobSequence(secondSeq.size());
	for (size_t i = 0; i < JacobSeq.size(); i++) {
		size_t secondIndex = JacobSeq[i] - 1;
		if (secondIndex >= 0 && secondIndex < secondSeq.size()) {
			int insertNumber = secondSeq[secondIndex];
			//Get the insert position of the number using upper_bound
			std::vector<int>::iterator it = std::upper_bound(main.begin(), main.end(), insertNumber);
			main.insert(it, insertNumber);
		}
	}
	myVector = main;
    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - start.tv_sec) * 1000000.0;
    elapsed += (end.tv_usec - start.tv_usec);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector: " << elapsed << " us" << std::endl;
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
	std::cout << std::endl;
}

const char* PmergeMe::MyException::what() const throw() {
	return "Error";
}
