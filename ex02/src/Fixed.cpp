#include <Fixed.hpp>

//const Fixed Fixed::_minValue = Fixed(-1.0f);
const Fixed Fixed::_minValue = Fixed(-(1 << Fixed::_fractionalBits));

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
		std::cout << "Int constructor called" << std::endl;
	_value = (value << _fractionalBits);
}

// This copy constructor takes a float, scales it using a scaling factor
// determined by fractionalBits, rounds the result with `roundf` and
// assign it to _value.
Fixed::Fixed(const float value) {
	if (MESSAGE)
		std::cout << "Float constructor called" << std::endl;
	_value = (roundf(value * (1 << _fractionalBits)));
}

// Where for?
Fixed::Fixed(const Fixed& f) {
	if (MESSAGE)
		std::cout << "Copy constructor called" << std::endl;
	_value = f.getRawBits();

}

// Where for?
Fixed&	Fixed::operator=(const Fixed& f) {
	if (MESSAGE)
		std::cout << "Copy assigment operator called" << std::endl;
	if (this != &f)
		_value = f.getRawBits();
	return (*this);

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

bool	Fixed::operator<(const Fixed& other) const {
	return (_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (_value >= other._value);
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const {
	return (_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (_value != other._value);
}

Fixed	Fixed::operator+(const Fixed& other) const {
	int	sum = _value + other._value;
	return (Fixed(sum / (1 << _fractionalBits)));
}

Fixed	Fixed::operator-(const Fixed& other) const {
	int	sum = _value - other._value;
	return (Fixed(sum / (1 << _fractionalBits)));
}

Fixed	Fixed::operator*(const Fixed& other) const {
	int	product = _value * other._value;
	return (Fixed(product >> (_fractionalBits * 2)));
}

Fixed	Fixed::operator/(const Fixed& other) const {
	int	quotient = _value / other._value;
//	int64_t numerator = static_cast<int64_t>(_value) << _fractionalBits;
//	int32_t quotient = static_cast<int32_t>((numerator / other._value) + ((numerator % other._value) >= (other._value >> 1)));
	return (Fixed(quotient));
}

Fixed&	Fixed::operator++(void) {
	if (*this == _minValue)
		_value = _minValue._value;
	else
		_value += (1 << _fractionalBits);
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	old(*this);
	++(*this);
	return (old);
}

Fixed&	Fixed::operator--(void) {
	_value -= (1 << _fractionalBits);
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	old(*this);
	--(*this);
	return (old);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed	Fixed::min(const Fixed a, const Fixed b) {
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed	Fixed::max(const Fixed a, const Fixed b) {
	return (a > b) ? a : b;
}

// Is this one needed for this exercise?
int	Fixed::getRawBits() const {
	if (MESSAGE)
		std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}
