
#include "../includes/Point.hpp"

Point::Point( void ): _x(Fixed(0)), _y(Fixed(0))
{}

Point::~Point( void )
{}

Point::Point(const Point& fixedObject) : _x(fixedObject._x), _y(fixedObject._y)
{}

Point::Point( const float x, const float y ): _x(Fixed(x)), _y(Fixed(y))
{}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}

Fixed Point::getX( void ) const
{
	return ( _x );
}

Fixed Point::getY( void ) const
{
	return ( _y );
}

// methode des 2 vecteurs
// P = A + w1(B - A) + w2(C + A))
// P est dans le triangle si w1 >= 0, w2 >= 0 et (w1 + w2) <=1
// ref : https://www.youtube.com/watch?v=HYAgJN3x4GA
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed Ax = a.getX();
    Fixed Ay = a.getY();
    Fixed Bx = b.getX();
    Fixed By = b.getY();
    Fixed Cx = c.getX();
    Fixed Cy = c.getY();
    Fixed Px = point.getX();
	Fixed Py = point.getY();

    Fixed denominator = ((By - Ay) * (Cx - Ax)) - ((Bx - Ax) * (Cy - Ay));
    if (denominator == Fixed(0))
        return false; // triangle dégénéré (surface nulle)

    Fixed w1 = ((Ax * (Cy - Ay)) + ((Py - Ay) * (Cx - Ax)) - (Px * (Cy - Ay))) / denominator;
    Fixed w2 = (Py - Ay - w1 * (By - Ay)) / (Cy - Ay);
    Fixed w3 = Fixed(1) - w1 - w2;

    return (w1 >= Fixed(0)) && (w2 >= Fixed(0)) && ((w1 - w2) <= Fixed(1));
}
