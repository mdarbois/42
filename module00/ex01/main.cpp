#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main(void)
{
  std::string input;
  PhoneBook instance;

  while (input != "EXIT")
  {
    std::cout << "What do you want to do?\n";
    std::getline(std::cin, input);

    if (input == "ADD")
      instance.add();
    else if (input == "SEARCH")
      instance.search();
    else if (input == "EXIT")
      break;
    else
      std::cout << "Invalid input. You can only ADD, SEARCH or EXIT\n";
  }
  return(0);
}
