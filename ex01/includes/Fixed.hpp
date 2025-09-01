

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
		
		
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif