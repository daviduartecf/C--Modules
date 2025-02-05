#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator =(const Brain& other);
		void ideaSetter(const std::string& string, int i);
		std::string ideaGetter(int i) const;
	private:
		std::string ideas[100];
};

#endif
