/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:13:15 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:13:16 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name ) {

  if ( N <= 0 )
		return ( NULL );
  Zombie *aZombieHorde = new Zombie[N];
  for (int i = 0; i < N; i++) {
		aZombieHorde[i].setName( name );
	}
	return ( aZombieHorde );
}
