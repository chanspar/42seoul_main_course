#include "Point.hpp"

Point::Point()
	: x(0), y(0)
{

}

Point::Point(float const x, float const y)
	: x(x), y(y)
{

}

Point::Point(const Point& rhs)
	: x(rhs.x), y(rhs.y)
{

}

Point& Point::operator=(const Point& rhs)
{
	const_cast<Fixed&>(x) = rhs.x;
	const_cast<Fixed&>(y) = rhs.y;

	return *this;
}

Point::~Point()
{

}

Fixed Point::crossProduct(Point const a, Point const b, Point const c)
{
	Fixed result((b.x - a.x) *
				(c.y - a.y) -
				(b.y - a.y) *
				(c.x - a.x));

	return result;
}

bool Point::innerProduct(Fixed a, Fixed b)
{
	Fixed result(a * b);

	if (result.getRawBits() > 0)
		return true;
	return false;
}
