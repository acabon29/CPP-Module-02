# include <Fixed.hpp>

#ifndef POINT_HPP
# define POINT_HPP


class Point {
	private :
		Fixed _x;
		Fixed _y;
	public :
		Point( void );
		~Point( void );
		Point (const Point& fixedObject);
		Point( const float x, const float y );

		Point &operator=(const Point &other);
		// void setX(float x);
		Fixed getX( void ) const;
		Fixed getY( void ) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif