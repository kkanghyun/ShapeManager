#include "rectangle.h"
#include <iostream>
#include <string>

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
	std::cout << "사각형 - (" << p1.x << "," << p1.y << "), ("
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

void Rectangle::save(std::ofstream& out)
{
	out << "사각형 - (" << std::to_string(p1.x) << "," << std::to_string(p1.y) << "), ("
		<< std::to_string(p2.x) << "," << std::to_string(p2.y) << ")" << '\n';
}

void Rectangle::load(std::ifstream& in)
{
	std::string str;
	char buf[100];
	in.getline(buf, 100, '(');
	in >> p1.x;
	in.getline(buf, 100, ',');
	in >> p1.y;
	in.getline(buf, 100, '(');
	in >> p2.x;
	in.getline(buf, 100, ',');
	in >> p2.y;
	in.getline(buf, 100);
}
