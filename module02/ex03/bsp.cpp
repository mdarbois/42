#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath>

Fixed	getTriangleArea( Point const a, Point const b, Point const c )
{
	Fixed	area = a.getX() * (b.getY() - c.getY())
		+ b.getX() * (c.getY() - a.getY())
		+ c.getX() * (a.getY() - b.getY()) / 2;
	Fixed	absArea( abs( area.toFloat() ) );
	return ( absArea );
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
  Fixed	areaTriangle = getTriangleArea(a, b, c);
	Fixed	areaPAB = getTriangleArea(point, a, b);
	Fixed	areaPBC = getTriangleArea(point, b, c);
	Fixed	areaPAC = getTriangleArea(point, a, c);

	if ( areaPAB != 0 && areaPBC != 0 && areaPBC != 0
		&& areaPAB + areaPBC + areaPAC <= areaTriangle )
		return ( true );
	return ( false );
}
