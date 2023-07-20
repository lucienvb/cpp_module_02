#include <Fixed.hpp>

Fixed::Fixed() {
	if (MESSAGE)
		std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value) {
	if (MESSAGE)
		std::cout << "Int constructor called" << std::endl;
	_value = (value << _fractionalBits);
}

Fixed::Fixed(const float value) {
	if (MESSAGE)
		std::cout << "Float constructor called" << std::endl;
	_value = (roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other) {
	if (MESSAGE)
		std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	if (MESSAGE)
		std::cout << "Copy assigment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return (*this);

}

Fixed::~Fixed() {
	if (MESSAGE)
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
	int		sum;
	Fixed	ans;

	sum = _value + other._value;
	ans._value = sum;
	return ans;
}

Fixed	Fixed::operator-(const Fixed& other) const {
	int		subtract;
	Fixed	ans;

	subtract = _value - other._value;
	ans._value = subtract;
	return ans;
}

// First the values of the current Fixed object (_value) and the other Fixed object (other._value) are multiplied
// and stores the result in the product variable. The explicit casting to float is performed to ensure that the
// multiplication is done in floating-point precision rather than integer precision.
// Afterward, the expression divides the product by 2^(2 * _fractionalBits), effectively scaling down the
// floating-point result to fit within the fixed-point representation. Finally, it returns a new Fixed object.
Fixed	Fixed::operator*(const Fixed& other) const {
	float	product;

    product = (float)_value * (float)other._value;
	return (Fixed(product / (1 << (2 * _fractionalBits))));
}

Fixed	Fixed::operator/(const Fixed& other) const {
	float	quotient;

    quotient = (float)_value / (float)other._value;
	return (Fixed(quotient * (1 << (2 / _fractionalBits))));
}

Fixed&	Fixed::operator++(void) {
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	old(*this);

	++(*this);
	return (old);
}

Fixed&	Fixed::operator--(void) {
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	old(*this);

	--(*this);
	return (old);
}

// The functions four below use a ternary conditional operator that works as follows.
// If the condition is true it returns the first value (a).
// If it's false it returns the second value (b).
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

int	Fixed::getRawBits() const {
	if (MESSAGE)
		std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}
