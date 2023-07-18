#ifndef FIXED_HPP
#define FIXED_HPP

// INCLUDES
#include <iostream>
#include <cmath>

#define MESSAGE 1

class Fixed {
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);

	float	toFloat(void) const;
    int 	toInt(void) const;

    ~Fixed();

private:
    int					_value;
    static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
