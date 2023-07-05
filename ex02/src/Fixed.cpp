#include <Fixed.hpp>

Fixed::Fixed() {
	if (MESSAGE)
		std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

// This copy constructor initializes a `Fixed` object with a fixed-point
// value derived from the integer input value.
// It uses a left shift operation to scale the integer value by a
// factor of 2 to the power of _fractionalBits (8), effectively converting
// it into fixed-point representation.
Fixed::Fixed(const int value) {
	if (MESSAGE)
		std::cout << "(int) Copy constructor called" << std::endl;
	_value = (value << _fractionalBits);
}

// This copy constructor takes a float, scales it using a scaling factor
// determined by fractionalBits, rounds the result with `roundf` and
// assign it to _value.
Fixed::Fixed(const float value) {
	if (MESSAGE)
		std::cout << "(float) Copy constructor called" << std::endl;
	_value = (roundf(value * (1 << _fractionalBits)));
}

Fixed::~Fixed() {
	if (MESSAGE)
		std::cout << "Destructor called" << std::endl;
}

// This function allows a `Fixed` object to be inserted into an output
// stream using the `<<` operator.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

// This method converts a fixed-point value to a float-point value.
// It does basically the opposite of the float constructor.
float	Fixed::toFloat() const {
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

// This method converts a fixed-point value to an integer value.
// It operates the right shift operation on _value, the opposite
// of the int constructor.
int	Fixed::toInt() const {
	return (_value >> _fractionalBits);
}

bool	Fixed::operator>(const Fixed& other) const {
	return (_value > other._value);
}
