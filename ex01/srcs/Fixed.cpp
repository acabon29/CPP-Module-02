
#include "../includes/Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int rawBits )
{
	_fixedPointValue = rawBits << _fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float floatNumber )
{

	_fixedPointValue = roundf(floatNumber * (1 << _fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed& fixedObject)
{
	std::cout << "Copy constructor called" << std::endl;
	// _fixedPointValue = fixedObject._fixedPointValue;
	*this = fixedObject;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other._fixedPointValue;
	}
	return ( *this );
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return ( _fixedPointValue );
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return ( (float)_fixedPointValue / (1 << _fractionalBits) );
}

int Fixed::toInt(void) const {
	return ( _fixedPointValue >> _fractionalBits );
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

