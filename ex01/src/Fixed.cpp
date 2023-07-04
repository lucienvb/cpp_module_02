#include <Fixed.hpp>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Copy constructor called" << std::endl;
	_value = (value << _fractionalBits);
}

Fixed::Fixed(const float value) {
	std::cout << "Copy constructor called" << std::endl;
	_value = (roundf(value * (1 << _fractionalBits)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

float	Fixed::toFloat() const {
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int	Fixed::toInt() const {
	return (_value >> _fractionalBits);
}


