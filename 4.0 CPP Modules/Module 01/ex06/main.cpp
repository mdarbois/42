/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:51:15 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 17:51:16 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
  {
		std::cout << "Sorry i need to understand which level you are currently" << std::endl;
    return (0);
  }
  harl.complain(argv[1]);
	return (0);
}