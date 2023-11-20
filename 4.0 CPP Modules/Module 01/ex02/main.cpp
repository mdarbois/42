/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:37:46 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:37:47 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
