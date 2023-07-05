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

	float	toFloat(void) const;
	int 	toInt(void) const;


private:
	int					_value;
	static const int	_fractionalBits = 8;
};

#endif
