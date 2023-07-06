#include <Fixed.hpp>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//	Fixed const b( Fixed( 5.05f ));
//	Fixed const c( Fixed( 2 ) );
//
//	std::cout << b << std::endl;
//	std::cout << c << std::endl;
//	Fixed	d = b * c;
//	std::cout << d << std::endl;
//	a = 2.123f;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}