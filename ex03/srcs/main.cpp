#include <iostream>
#include <Fixed.hpp>
#include <Point.hpp>

// BSP = Binary Space Partitionin

void test(const char* label, const Point& a, const Point& b, const Point& c, const Point& p) {
    static int nbTest = 0;
	std::cout << "Test " << nbTest << ": " << std::endl;
	std::cout << label << ": ";
    if (bsp(a, b, c, p))
        std::cout << "Dans le triangle\n" << std::endl;
    else
        std::cout << "Error : pas dans le triangle\n" << std::endl;
}

int main( void ) {
	Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    // Point a l'intereur du triangle
    Point p1(1, 1);
    test("Point a l'intereur du triangle", a, b, c, p1);

    // Point en dehors du triangle
    Point p2(6, 6);
    test("Point en dehors du triangle", a, b, c, p2);

    // Point sur un bord (AB) du triangle
    Point p3(2.5, 0);
    test("Point sur un bord (AB) du triangle", a, b, c, p3);

    // Point sur un bord (AC) du triangle
    Point p4(0, 2.5);
    test("Point sur un bord (AC) du triangle", a, b, c, p4);

    // Point sur un bord (BC) du triangle
    Point p5(2.5, 2.5);
    test("Point sur un bord (BC) du triangle", a, b, c, p5);

    // Point sur un sommet (A) du triangle
    Point p6(0, 0);
    test("Point sur un sommet (A) du triangle", a, b, c, p6);

    // Triangle avec les 3 points allignes
    Point d(0, 0);
    Point e(2.5, 0);
    Point f(5, 0);
    Point p7(2.5, 0);
    test("Triangle avec les 3 points allignes", d, e, f, p7);

    return 0;
}