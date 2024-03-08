#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed caseA1 = Point::crossProduct(a, b, point);
	Fixed caseA2 = Point::crossProduct(a, b, c);
	Fixed caseB1 = Point::crossProduct(a, c, point);
	Fixed caseB2 = Point::crossProduct(a, c, b);
	Fixed caseC1 = Point::crossProduct(b, c, point);
	Fixed caseC2 = Point::crossProduct(b, c, a);

	if (Point::innerProduct(caseA1, caseA2) && Point::innerProduct(caseB1, caseB2) && Point::innerProduct(caseC1, caseC2))
		return true;
	return false;

}
