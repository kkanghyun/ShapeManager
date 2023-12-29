#include "triangle.h"
#include <iostream>
#include <string>

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

void Triangle::save(std::ofstream& out)
{
	out << "»ï°¢Çü - (" << std::to_string(p1.x) << "," << std::to_string(p1.y) << "), ("
		<< std::to_string(p2.x) << "," << std::to_string(p2.y) << "), ("
		<< std::to_string(p3.x) << "," << std::to_string(p3.y) << ")" << '\n';
}

void Triangle::load(std::ifstream& in)
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
	in.getline(buf, 100, '(');
	in >> p3.x;
	in.getline(buf, 100, ',');
	in >> p3.y;
	in.getline(buf, 100);
}
