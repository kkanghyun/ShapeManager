#include "triangle.h"
#include <iostream>

Triangle::Triangle()
	: p1(), p2(), p3()
{
	setType(EShape::TRIANGLE);
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
	: p1(a), p2(b), p3(c)
{
}

Triangle::Triangle(const Triangle& other)
	: p1(other.p1), p2(other.p2), p3(other.p3)
{
}

Triangle::~Triangle()
{
}

void Triangle::draw() const
{
	std::cout << "»ï°¢Çü - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << "), ("
		<< p3.x << "," << p3.y << ")" << '\n';
}

void Triangle::insertPoint()
{
	std::cout << "p1 x: ";
	std::cin >> p1.x;
	std::cout << "p1 y: ";
	std::cin >> p1.y;

	std::cout << '\n';

	std::cout << "p2 x: ";
	std::cin >> p2.x;
	std::cout << "p2 y: ";
	std::cin >> p2.y;

	std::cout << '\n';

	std::cout << "p3 x: ";
	std::cin >> p3.x;
	std::cout << "p3 y: ";
	std::cin >> p3.y;
}
