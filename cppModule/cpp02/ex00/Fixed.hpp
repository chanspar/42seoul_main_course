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
	~Fixed();
	Fixed(const Fixed& rhs);
	Fixed& operator=(const Fixed& rhs);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif
