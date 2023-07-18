#ifndef FIXED_HPP
#define FIXED_HPP

// INCLUDES
#include <iostream>
#include <cmath>

#define MESSAGE 0

class Fixed {
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& f);
	Fixed&	operator=(const Fixed& f);

	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static 			Fixed&	min(Fixed& a, Fixed& b);
	static const	Fixed	min(const Fixed a, const Fixed b);
	static 			Fixed&	max(Fixed& a, Fixed& b);
	static const 	Fixed	max(const Fixed a, const Fixed b);

	float	toFloat(void) const;
	int 	toInt(void) const;
	int		getRawBits(void) const;

	~Fixed();

private:
	int					_value;
	static const int	_fractionalBits = 8;
	static const Fixed	_minValue;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
