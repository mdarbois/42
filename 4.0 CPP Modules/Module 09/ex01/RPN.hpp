#ifndef RND_HPP
#define RND_HPP

#include <cctype>
#include <cstddef>
#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>


class RPN {
   public:
    RPN();
    RPN(RPN const &src);
    RPN &operator=(RPN const &rhs);
    ~RPN();
    void checkInput(std::string input);
    bool checkChar(std::string input);
    void calculate();
    int printOperand(char operand);
    class TooShortException: public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
    class InvalidCharException: public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
    private:
    std::string _input;
    std::stack<int> _stack;
};

#endif