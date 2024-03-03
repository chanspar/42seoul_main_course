#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed 
{
private:
	int	fixedValue;
	const static int bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& rhs);
	Fixed& operator=(const Fixed& rhs);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif
