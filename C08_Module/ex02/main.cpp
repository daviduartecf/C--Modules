#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main() {
    std::cout << "\n*** MutantStack Tests ***\n" << std::endl;

    MutantStack<int> mstack;

    std::cout << "Pushing elements: 5, 17, 3, 7, 42" << std::endl;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(7);
    mstack.push(42);

    std::cout << "Top element: " << mstack.top() << std::endl;

	if (mstack.empty())
		std::cout << "Mstack is empty" << std::endl;
	else
		std::cout << "Mstack is not empty!" << std::endl;

    std::cout << "Popping top element..." << std::endl;
    mstack.pop();

    std::cout << "New top element: " << mstack.top() << std::endl;
    std::cout << "Stack size: " << mstack.size() << std::endl;

    std::cout << "\nIterating using normal iterators:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "\nIterating using reverse iterators:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    std::cout << "\nTesting const iterators:" << std::endl;
    const MutantStack<int> constStack = mstack;
    for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    std::cout << "\nTesting const reverse iterators:" << std::endl;
    for (MutantStack<int>::const_reverse_iterator crit = constStack.rbegin(); crit != constStack.rend(); ++crit) {
        std::cout << *crit << " ";
    }
    std::cout << std::endl;

    std::cout << "\nComparing with std::list:" << std::endl;
    std::list<int> lst(mstack.begin(), mstack.end());
    std::cout << "List contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
	std::cout << "Reverse List contents: ";
	for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}
