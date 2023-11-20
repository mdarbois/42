/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:02:09 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 15:02:11 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdio>

int main(int argc, char** argv)
{
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else
    for (size_t i = 1; argv[i]; i++)
    {
      for (size_t x = 0; x < std::char_traits<char>::length(argv[i]); x++)
        putchar(toupper(argv[i][x]));
    }
  std::cout << "\n";
  return 0;
}
