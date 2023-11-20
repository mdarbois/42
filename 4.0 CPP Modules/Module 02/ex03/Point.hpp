/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:48:59 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/13 15:49:00 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <iostream>
#include "Fixed.hpp"


class Point {
  private:
    Fixed const _x;
    Fixed const _y;

  public:
    Point( void );
    Point (Fixed const x, Fixed const y);
    Point ( Point const &src);
    Point &operator=(Point const &rhs);
		~Point( void );

    Fixed const & getX( void ) const;
    Fixed const & getY( void ) const;
};

#endif
