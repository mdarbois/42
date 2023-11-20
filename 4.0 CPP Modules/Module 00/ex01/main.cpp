/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:13:28 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 15:13:29 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
