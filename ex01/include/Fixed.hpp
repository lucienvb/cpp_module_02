#ifndef FIXED_HPP
#define FIXED_HPP

// INCLUDES
#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	friend	std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

	float	toFloat(void) const;
	int 	toInt(void) const;


private:
	int					_value;
	static const int	_fractionalBits = 8;
};

#endif
