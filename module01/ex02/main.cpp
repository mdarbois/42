#include <iostream>

int main ( void )
{
  std::string str;
  str = "HI THIS IS BRAIN";

  std::string *stringPTR = &str;
  std::string &stringREF = str;
  std::cout << "Memory addresses:" << std::endl;
  std::cout << "str=" << &str << std::endl;
  std::cout << "stringPTR=" << stringPTR << std::endl;
  std::cout << "stringREF=" << &stringREF << std::endl;
  std::cout << "Values" << std::endl;
  std::cout << "str=" << str << std::endl;
  std::cout << "stringPTR=" << *stringPTR << std::endl;
  std::cout << "stringREF=" << stringREF << std::endl;
}
