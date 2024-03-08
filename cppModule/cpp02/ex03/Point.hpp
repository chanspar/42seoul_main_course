#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(float const x, float const y);
	Point(const Point& rhs);
	Point& operator=(const Point& rhs);
	~Point();
	static Fixed crossProduct(Point const a, Point const b, Point const c);
	static bool innerProduct(Fixed a, Fixed b);
};

#endif
