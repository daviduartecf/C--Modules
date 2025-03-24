#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stack>
# include <sstream>
# include <fstream>
# include <climits>
# include <cstdlib>

class RPN {
    public:
		//ORTHODOX CANONICAL FORM
        RPN(); //posso deixar este?
        virtual ~RPN();
        RPN(const RPN& other);
        RPN& operator = (const RPN& other);
		RPN(std::string input);
    private:
        std::stack<std::string> myStack;
};

#endif // RPN_HPP
