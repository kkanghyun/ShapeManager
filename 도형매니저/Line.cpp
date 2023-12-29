#include "Line.h"
#include <iostream>
#include <string>

Line::Line()
	: p1(), p2()
{
	setType(EShape::LINE);
}

Line::Line(const Point& a, const Point& b)
	: p1(a), p2(b)
{
}

Line::Line(const Line& other)
	: p1(other.p1), p2(other.p2)
{
}

Line::~Line()
{
}

void Line::draw() const
{
	std::cout << "라인 - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << ")" << '\n';
}

void Line::insertPoint()
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

void Line::save(std::ofstream& out)
{
	out << "라인 - (" << std::to_string(p1.x) << "," << std::to_string(p1.y) << "), ("
		<< std::to_string(p2.x) << "," << std::to_string(p2.y) << ")" << '\n';
}

void Line::load(std::ifstream& in)
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
