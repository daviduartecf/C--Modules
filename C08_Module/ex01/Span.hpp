#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
	public:
		//orthodox canonical form
		Span();
		Span(int N);
		~Span();
		Span& operator = (const Span& other);
		Span(const Span& other);
		//member functions
		void addNumber(int num);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);
		//exceptions
		class SpanFullException: public std::exception {
			public:
				const char* what() const throw();
		};
		class NoSpanException: public std::exception {
			public:
				const char* what() const throw();
		};
	private:
		unsigned int size;
		std::vector<int> vec;
};

#endif
