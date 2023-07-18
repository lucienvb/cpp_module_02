#ifndef FIXED_HPP
#define FIXED_HPP

// INCLUDES
#include <iostream>

// The Orthodox Canonical From (OCF) includes the following:
// 1) A constructor
// 2) A copy constructor
// 3) An assignation operator
// 4) A destructor
class Fixed {
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	int		getRawBits(void) const;
    void	setRawBits(int const raw);

    ~Fixed();

private:
	int					_value;
	static const int	_fractionalBits;
};

#endif
