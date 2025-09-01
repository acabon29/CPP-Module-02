

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
		Fixed (const Fixed& fixedObject);
		~Fixed( void );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
		Fixed &operator=(const Fixed &other);
		
};


#endif