#include "Fixed.hpp"

Fixed::Fixed()
	: RawBits(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &rhs)
{
	// std::cout << "Copy constructor called\n";
	*this = rhs;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
	// std::cout << "Copy assignment operator called\n";
	RawBits = rhs.RawBits;

	return *this;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called\n";
	return RawBits;
}

void Fixed::setRawBits( int const raw )
{
	RawBits = raw;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called\n";
	RawBits = num << fractionalBits;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called\n";
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

bool Fixed::operator >(const Fixed& rhs) const
{
	return (RawBits > rhs.RawBits);
}

bool Fixed::operator <(const Fixed& rhs) const
{
	return (RawBits < rhs.RawBits);
}

bool Fixed::operator >=(const Fixed& rhs) const
{
	return (RawBits >= rhs.RawBits);
}

bool Fixed::operator <=(const Fixed& rhs) const
{
	return (RawBits <= rhs.RawBits);
}

bool Fixed::operator ==(const Fixed& rhs) const
{
	return (RawBits == rhs.RawBits);
}

bool Fixed::operator !=(const Fixed& rhs) const
{
	return (RawBits != rhs.RawBits);
}

//Fixed& 아닌 이유 : ex a = b + c + b 일경우 2b + 2c로 나옴
Fixed Fixed::operator +(const Fixed& rhs) const
{
	Fixed result;
	result.RawBits = this->RawBits + rhs.RawBits;

	return result;
}
	
Fixed Fixed::operator -(const Fixed& rhs) const
{
	Fixed result;
	result.RawBits = this->RawBits - rhs.RawBits;

	return result;
}
	
Fixed Fixed::operator *(const Fixed& rhs) const
{
	Fixed result;
	result.RawBits = (this->RawBits * rhs.RawBits) >> fractionalBits; 

	return result;
}
	
Fixed Fixed::operator /(const Fixed& rhs) const
{
	Fixed result;
	result.RawBits = (this->RawBits << fractionalBits) / rhs.RawBits;

	return result;
}

//전위
Fixed& Fixed::operator ++()
{
	RawBits += 1;

	return *this;
}

//후위
Fixed Fixed::operator ++(int)
{
	Fixed temp(*this);

	RawBits += 1;
	return temp;
}

Fixed& Fixed::operator --()
{
	RawBits -= 1;

	return *this;
}

Fixed Fixed::operator --(int)
{
	Fixed temp(*this);

	RawBits -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& fixedNumber1, Fixed& fixedNumber2)
{
	if (fixedNumber1 <= fixedNumber2)
		return fixedNumber1;
	else
		return fixedNumber2;
}

const Fixed& Fixed::min(const Fixed& fixedNumber1, const Fixed& fixedNumber2)
{
	if (fixedNumber1 <= fixedNumber2)
		return fixedNumber1;
	else
		return fixedNumber2;
}

Fixed& Fixed::max(Fixed& fixedNumber1, Fixed& fixedNumber2)
{
	if (fixedNumber1 >= fixedNumber2)
		return fixedNumber1;
	else
		return fixedNumber2;
}

const Fixed& Fixed::max(const Fixed& fixedNumber1, const Fixed& fixedNumber2)
{
	if (fixedNumber1 >= fixedNumber2)
		return fixedNumber1;
	else
		return fixedNumber2;
}
