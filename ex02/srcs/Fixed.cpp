
#include "../includes/Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _fixedPointValue(0)
{}

Fixed::Fixed( const int rawBits )
{
	_fixedPointValue = rawBits << _fractionalBits;
}

Fixed::Fixed( float floatNumber )
{
	_fixedPointValue = roundf(floatNumber * (1 << _fractionalBits));
}

Fixed::~Fixed()
{}

Fixed::Fixed (const Fixed& fixedObject)
{
	*this = fixedObject;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other) {
		this->_fixedPointValue = other._fixedPointValue;
	}
	return ( *this );
}

int Fixed::getRawBits( void ) const
{
	return ( _fixedPointValue );
}

void Fixed::setRawBits( int const raw )
{
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return ( (float)_fixedPointValue / (1 << _fractionalBits) );
}

int Fixed::toInt(void) const {
	return ( _fixedPointValue >> _fractionalBits );
}

// operateurs de comparaison :

bool Fixed::operator>(const Fixed &fixed) const
{
	return ( _fixedPointValue > fixed._fixedPointValue );
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return ( _fixedPointValue < fixed._fixedPointValue );
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return ( _fixedPointValue >= fixed._fixedPointValue );
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return ( _fixedPointValue <= fixed._fixedPointValue );
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return ( _fixedPointValue == fixed._fixedPointValue );
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return ( _fixedPointValue != fixed._fixedPointValue );
}


// operateurs arithmetique :

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue + fixed._fixedPointValue);
	return (result);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue - fixed._fixedPointValue);
	return (result);
}

// perte de precision :
// Fixed Fixed::operator*(const Fixed &fixed) const
// {
// 	return ( Fixed((this->toFloat() * fixed.toFloat()) ) );
// }

// Fixed Fixed::operator/(const Fixed &fixed) const
// {
// 	return ( Fixed((this->toFloat() / fixed.toFloat()) ) );
// }

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	Fixed result;
	result.setRawBits((this->_fixedPointValue * fixed._fixedPointValue) >> this->_fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	Fixed result;
	result.setRawBits((this->_fixedPointValue << this->_fractionalBits) / fixed._fixedPointValue);
	return (result);
}


// fonctions post/pre-increment

// Pre-increment operator ++
Fixed Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}

// Pre-decrement operator --
Fixed Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}

// Post-increment operator ++
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue++;
	return tmp;
}

// Post-increment operator --
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue--;
	return tmp;
}


// fonctions autre

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return ( fixed1 );
	return ( fixed2 );
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return ( fixed1 );
	return ( fixed2 );
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
if (fixed1.getRawBits() < fixed2.getRawBits())
		return ( fixed1 );
	return ( fixed2 );
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
if (fixed1.getRawBits() < fixed2.getRawBits())
		return ( fixed1 );
	return ( fixed2 );
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return ( o );
}