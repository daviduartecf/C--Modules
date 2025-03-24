#include "Span.hpp"
#include <limits>
#include <algorithm>

const char* Span::SpanFullException::what() const throw() {
	return "Span is already full!";
}

const char* Span::NoSpanException::what() const throw() {
	return "No sufficient numbers!";
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (vec.size() + std::distance(begin, end) > size)
		throw SpanFullException();
	vec.insert(vec.end(), begin, end);
}

int Span::shortestSpan(void) {
	if (vec.size() < 2)
		throw NoSpanException();
	std::vector<int> sortedVec = vec;
	std::sort(sortedVec.begin(), sortedVec.end());

	int minSpan = std::numeric_limits<int>::max();
	for (unsigned int i = 1; i < sortedVec.size(); i ++) {
		minSpan = std::min(minSpan, sortedVec[i] - sortedVec[i - 1]);
	}
	return minSpan;
}

int Span::longestSpan(void) {
	if (vec.size() < 2)
		throw NoSpanException();
	std::vector<int> sortedVec = vec;
	std::sort(sortedVec.begin(), sortedVec.end());

	int maxSpan = sortedVec.back() - sortedVec.front();
	return maxSpan;
}

void Span::addNumber(int num) {
	if (vec.size() >= size)
		throw SpanFullException();
	vec.push_back(num);
}

Span::Span(): size(0) {}

Span::Span(int N): size(N) {
	vec.reserve(N);
}

Span::~Span() {}

Span& Span::operator = (const Span& other) {
	if (this != &other) {
		size = other.size;
		vec = other.vec;
	}
	return *this;
}

Span::Span(const Span& other): size(other.size), vec(other.vec) {}
