#include "RPN.hpp"
#include <cctype>
#include <exception>

RPN::RPN() {}

RPN::RPN(std::string input) : str(input) {}

RPN::RPN(RPN const &src) {
	*this = src;
}

RPN &RPN::operator=(RPN const &rhs) {
	this->str = rhs.getStr();
	return (*this);
}

RPN::~RPN(void) {}

std::string RPN::getStr(void) const {
	return str;
}

void RPN::singleOperation() {
	int	operand1, operand2, result;
	char op;

	operand2 = numbers.top();
	numbers.pop();
	operand1 = numbers.top();
	numbers.pop();
	op = operators.top();
	operators.pop();
	switch (op)
	{
		case 42:
			result = operand1 * operand2;
			break;
		case 43:
			result = operand1 + operand2;
			break;
		case 45:
			result = operand1 - operand2;
			break;
		case 47:
			if (operand2 == 0)
				throw std::runtime_error("Error: divide by zero exception");
			result = operand1 / operand2;
			break;
		default:
			std::cout << "Error" << std::endl;
	}
	numbers.push(result);
}

void RPN::start(void) {
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			numbers.push(str[i] - '0');
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			operators.push(str[i]);
		else if (str[i] != ' ')
		{
			std::cout << "Error" << std::endl;
			return ;
		}
		if (operators.size() == 1 && numbers.size() >= 2)
			singleOperation();
		else if (operators.size() == 1)
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	if (numbers.size() == 1 && operators.empty())
			std::cout << "Result is: " << numbers.top() << std::endl;
	else
		std::cout << "Error" << std::endl;
}
