#ifndef FIXED_HPP
#define FIXED_HPP

// INCLUDES
#include <iostream>

// The Orthodox Canonical From (OCF) includes the following:
// 1) A constructor
// 2) A copy constructor
// 3) A destructor
// 4) An assignation operator
class Fixed {
public:
	Fixed();
	Fixed(const Fixed& other);
	~Fixed();

	Fixed& operator=(const Fixed& other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_value;
	static const int	_fractionalBits;
};

#endif
