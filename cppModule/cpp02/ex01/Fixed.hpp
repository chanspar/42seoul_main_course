#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
	float toFloat( void ) const; //고정소수점 실수버전
	int toInt( void ) const; //고정소수점 정수버전
};


#endif
