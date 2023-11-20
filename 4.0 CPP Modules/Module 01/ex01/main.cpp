/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:13:08 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:13:11 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie *zombieHorde( int N, std::string name );

int only_digits(std::string str)
{
  for (size_t i = 0; i < str.length(); i++) {
        if (!((str[i]) >= '0' && (str[i]) <= '9')) {
          return 1;
        }
  }
  return 0;
}

int	getN( void )
{
	int	n;
    std::string str;

    str = "";
	std::cout << "How many zombies do you want in your horde?" << std::endl;
	while (str == "" ) {
		std::getline(std::cin, str);
    if (str.empty() && !only_digits(str))
        std::cout << "Field must not be empty and contains only digits";
	}
    std::stringstream container(str);
    container >> n;
	return (n);
}

std::string getName(void)
{
  std::string str;

  str = "";
	std::cout << "What's the name of your horde?" << std::endl;
	while (str == "" ) {
		std::getline(std::cin, str);
    if (str.empty())
        std::cout << "Field must not be empty, try again" << std::endl;
	}
	return (str);
}

int main (void) {

  int			nb;
	std::string name;

  nb = getN();
  name = getName();
  std::cout << "Creating " << name << " horde of " << nb << " zombies" << std::endl;
  Zombie	*horde = zombieHorde(nb, name);
  if ( horde == NULL )
	{
		std::cout << "Sorry problem with the horde." << std::endl;
		return ( 1 );
	}
  for ( int i = 0; i < nb; i++ )
		horde[i].announce();
  std::cout << "Destroying zombies" << std::endl;
	delete [] horde;
	return ( 0 );

}
