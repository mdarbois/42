#include "RPN.hpp"

RPN::RPN() {
   std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(RPN const &src) {
    this->_input = src._input;
    std::cout << "RPN copy constructor called" << std::endl;
  }
  
RPN &RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
        _input = rhs._input;
    }
    std::cout << "RPN copy assignment operator called" << std::endl;
	return *this;
}

RPN::~RPN() {
      std::cout << "RPN destructor called" << std::endl;
}

void RPN::checkInput(std::string input) {
  if (input.length() < 3)
    throw (RPN::TooShortException());
  if (checkChar(input) == false)
   throw (RPN::InvalidCharException());
  _input = input;
}

bool RPN::checkChar(std::string input) {
	unsigned int digits = 0, operands = 0;
	for (size_t i = 0; i < input.length(); i++) {
		if (std::string("0123456789 -+*/").find(input[i]) == std::string::npos)
      return false;
		if (i > 0 && input[i] == ' ' && input[i - 1] == ' ')
      throw std::logic_error("Consecutives spaces");
		if (i > 0 && input[i] != ' ' && input[i - 1] != ' ')
      throw std::logic_error("Missing spaces");
		if (std::string("0123456789").find(input[i]) != std::string::npos)
      digits++;
		if (std::string("-+*/").find(input[i]) != std::string::npos)
      operands++;
	}
	if (operands + 1 != digits)
    throw std::logic_error("Number of operands is wrong");
	return true;
}

void RPN::calculate() {
	for (size_t i = 0; i < _input.length(); i++) {
		if (std::isdigit(_input[i])) {
			_stack.push(_input[i] - '0');
		} else if (std::string("-+*/").find(_input[i]) != std::string::npos) {
			_stack.push(printOperand(_input[i]));
			//std::cout << _stack.top() << " " << std::endl;
		}
	}
	std::cout << _stack.top() << std::endl;
}

int RPN::printOperand(char operand) {
	if (_stack.size() < 2)
    throw std::logic_error("Invalid order");
	int num2 = _stack.top();
	_stack.pop();
	int num1 = _stack.top();
	_stack.pop();
    if (operand == '+')
      return num1 + num2; // std::cout << " " << num1 << " + " << num2 << " = ", num1 + num2;
	  if (operand == '-')
      return num1 - num2; //std::cout << " " << num1 << " - " << num2 << " = ", num1 - num2;
	  if (operand == '*')
      return num1 * num2; //std::cout << " " << num1 << " * " << num2 << " = ", num1 * num2;
	  if (operand == '/')
      return num1 / num2;//std::cout << " " << num1 << " / " << num2 << " = ", num1 / num2;
  return (1);
}

const char *	RPN::TooShortException::what(void) const throw()
{
	return ("Expression is too short.");
}

const char *	RPN::InvalidCharException::what(void) const throw()
{
	return ("Invalid char in the expression.");
}