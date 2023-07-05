#ifndef FIXED_HPP
#define FIXED_HPP

// INCLUDES
#include <iostream>

#define MESSAGE 0

class Fixed {
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	friend	std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

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

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static 			Fixed&	min(Fixed& a, Fixed& b);
	static const	Fixed	min(const Fixed a, const Fixed b);
	static 			Fixed&	max(Fixed& a, Fixed& b);
	static const 	Fixed	max(const Fixed a, const Fixed b);

	float	toFloat(void) const;
	int 	toInt(void) const;


private:
	int					_value;
	static const int	_fractionalBits = 8;
};

#endif
