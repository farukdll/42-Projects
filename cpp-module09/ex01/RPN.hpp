#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <stack>

class RPN {
	private:
		std::string str;
		std::stack<char> operators;
		std::stack<int> numbers;

	public:
		std::string	getStr(void) const;
		RPN();
		RPN(std::string input);
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		~RPN();
		void start();
		void singleOperation();
};

#endif
