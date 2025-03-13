#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack();
		~MutantStack();
		MutantStack& operator = (const MutantStack& other);
		MutantStack(const MutantStack& other);
		typedef typename MutantStack<T>::container_type::iterator iterator;
		typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
		typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
