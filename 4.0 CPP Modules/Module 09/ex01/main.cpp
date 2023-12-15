#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc < 2)
    {
      std::cout << "wrong number of arguments" << std::endl;
      return (1);
    }
    try{
        RPN rpn;
		rpn.checkInput(argv[1]);
		rpn.calculate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}