#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed 
{
private:
	int	RawBits;
	static const int  fractionalBits = 8;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed(const Fixed& rhs);
	Fixed& operator=(const Fixed& rhs);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	
	bool operator >(const Fixed& rhs) const;
	bool operator <(const Fixed& rhs) const;
	bool operator >=(const Fixed& rhs) const;
	bool operator <=(const Fixed& rhs) const;
	bool operator ==(const Fixed& rhs) const;
	bool operator !=(const Fixed& rhs) const;

	Fixed operator +(const Fixed& rhs) const;
	Fixed operator -(const Fixed& rhs) const;
	Fixed operator *(const Fixed& rhs) const;
	Fixed operator /(const Fixed& rhs) const;

	Fixed& operator ++();
	Fixed operator ++(int);
	Fixed& operator --();
	Fixed operator --(int);

	static Fixed& min(Fixed& fixedNumber1, Fixed& fixedNumber2);
	static const Fixed& min(const Fixed& fixedNumber1, const Fixed& fixedNumber2);
	static Fixed& max(Fixed& fixedNumber1, Fixed& fixedNumber2);
	static const Fixed& max(const Fixed& fixedNumber1, const Fixed& fixedNumber2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


#endif
