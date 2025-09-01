

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {

	private :
		int	_fixedPointValue;
		const static int _fractionalBits;
		
	public :
		Fixed( void );
		Fixed( int rawBits );
		Fixed( float floatNumber );
		Fixed (const Fixed& fixedObject);
		~Fixed( void );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat(void) const;
		int toInt(void) const;
		
		Fixed &operator=(const Fixed &other);

		bool operator>(const Fixed &fixed)const;
		bool operator<(const Fixed &fixed)const;
		bool operator>=(const Fixed &fixed)const;
		bool operator<=(const Fixed &fixed)const;
		bool operator==(const Fixed &fixed)const;
		bool operator!=(const Fixed &fixed)const;

		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;

		Fixed operator++(); // pas d'argument = Pre-increment
		Fixed operator--();
		Fixed operator++(int);// d'argument = Post-increment
		Fixed operator--(int);

		static Fixed &max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
		
		
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif