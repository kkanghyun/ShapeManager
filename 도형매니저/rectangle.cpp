#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle()
	: p1(), p2()
{
	setType(EShape::RECTANGLE);
}

Rectangle::Rectangle(const Point& a, const Point& b)
	: p1(a), p2(b)
{
}

Rectangle::Rectangle(const Rectangle& other)
	: p1(other.p1), p2(other.p2)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw() const
{
	std::cout << "»ç°¢Çü - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << ")" << '\n';
}

void Rectangle::insertPoint()
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
}
