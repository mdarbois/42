#include "PhoneBook.hpp"
#include <iostream>

int PhoneBook::_nbContact = 0;

int PhoneBook::getNbContact(void)
{
  return PhoneBook::_nbContact - 1;
}

int only_digits(std::string str)
{
  for (size_t i = 0; i < str.length(); i++) {
        if (!((str[i]) >= '0' && (str[i]) <= '9')) {
          return 1;
        }
  }
  return 0;
}

void PhoneBook::add(void)
{
  std::string str;
  int i;

  str = "";

  if (_nbContact >= 8)
    i = 0;
  else
  {
    i = this->_nbContact % 8;
    PhoneBook::_nbContact += 1;
  }
    while (str == "")
    {
      std::cout << "Enter a first name: ";
      std::getline(std::cin, str);
      if (str.empty())
        std::cout << "Field must not be empty.";
      else
        this->_contacts[i].set_first_name(str);
    }
    str = "";
    while (str == "")
    {
      std::cout << "Enter a last name: ";
      std::getline(std::cin, str);
      if (str.empty())
        std::cout << "Field must not be empty.";
      else
        this->_contacts[i].set_last_name(str);
    }
    str = "";
    while (str == "")
    {
      std::cout << "Enter a nickname: ";
      std::getline(std::cin, str);
      if (str.empty())
        std::cout << "Field must not be empty.";
      else
        this->_contacts[i].set_nickname(str);
    }
    str = "";
    while (str == "")
    {
      std::cout << "Enter a phone number: ";
      std::getline(std::cin, str);
      if (str.empty() && !only_digits(str))
        std::cout << "Field must not be empty and contains only digits";
      else
        this->_contacts[i].set_phone_number(str);
    }
    str = "";
    while (str == "")
    {
      std::cout << "Enter a darkest secret: ";
      std::getline(std::cin, str);
      if (str.empty())
        std::cout << "Field must not be empty.";
      else
      this->_contacts[i].set_darkest_secret(str);
    }

}

void PhoneBook::print(int i)
{
    std::string str;
    str = "";
    str = std::to_string(i);
    std::cout << "    " + str + "    ";
    str = _contacts[i].get_first_name();
    if (str.length() > 10)
    str = str.substr(0, 9)+".";
    while (str.length() < 10)
      str = " " + str;
    std::cout << "|" << str;
    str = _contacts[i].get_last_name();
    if (str.length() > 10)
    str = str.substr(0, 9)+".";
    while (str.length() < 10)
      str = " " + str;
    std::cout << "|" << str;
    str = _contacts[i].get_nickname();
    if (str.length() > 10)
    str = str.substr(0, 9)+".";
    while (str.length() < 10)
      str = " "+str;
    std::cout << "|" << str << "\n";
}

void PhoneBook::search(void)
{
  int i;
  std::string str;
  i = 0;
  str = "";
  std::cout << _nbContact;
  std::cout << "\nHere is the list of all saved contacts:\n";
  std::cout << "  Index  |First Name| Last Name| Nickname \n";
  while (i < _nbContact)
  {
    PhoneBook::print(i);
    i += 1;
  }
  str = "";
  std::cout << "\nWanna see a specific contact? Give me the index\n";
  while (str == "")
  {
    std::getline(std::cin, str);
    if (!str.empty() && !only_digits(str) && stoi(str) <= (_nbContact - 1))
    {
      std::cout << "First name: " << _contacts[stoi(str)].get_first_name() << std::endl;
      std::cout << "Last name: " << _contacts[stoi(str)].get_last_name() << std::endl;
      std::cout << "Nickname: " << _contacts[stoi(str)].get_nickname() << std::endl;
      std::cout << "Phone number: " << _contacts[stoi(str)].get_phone_number() << std::endl;
      std::cout << "Darkest secret: " << _contacts[stoi(str)].get_darkest_secret() << std::endl;
    }
    else
    {
      std::cout << "\nGive me a VALID index\n";
      str = " ";
    }
  }
}
