#include "Fixed.hpp"

Fixed::Fixed()
	: RawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << "Copy constructor called\n";
	*this = rhs;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called\n";
	RawBits = rhs.RawBits;

	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return RawBits;
}

void Fixed::setRawBits( int const raw )
{
	RawBits = raw;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	RawBits = num << fractionalBits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	RawBits = roundf(num * (1 << fractionalBits));
}

float Fixed::toFloat( void ) const
{
	return ((float)RawBits / (1 << fractionalBits));
}

int Fixed::toInt( void ) const
{
	return (RawBits >> fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
