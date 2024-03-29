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
	RawBits = rhs.getRawBits();
}

// =  Fixed& 반환 이유 a=b=c같은 형태의 코드가 정상작동하려고
Fixed& Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called\n";
	RawBits = rhs.getRawBits();

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
