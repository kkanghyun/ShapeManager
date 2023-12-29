#include "circle.h"
#include <iostream>
#include <string>

Circle::Circle() 
	: center(), rad(0.0)
{
}

// ��������ڸ� ���α׷��� ������ �ִٸ� ��������� ���� �����ؾ� �Ѵ�.
// ��������ڸ� ���α׷��ϸ鼭 �ƹ��͵� ���� ������ ��������� ������� �ʴ´�.

Circle::Circle(const Point& c, double r)
	: center(c), rad(r)
{
	setType(EShape::CIRCLE);
}

Circle::Circle(const Circle& other)
	: center(other.center), rad(other.rad)
{
}

Circle::~Circle()
{
}

void Circle::draw() const
{
	// �׸��� �׸��� ��� ���ڷ� ������ ����Ѵ�
	std::cout << "�� - �߽���(" << center.x << "," << center.y
		<< ") ������ " << rad << '\n';
}

void Circle::insertPoint()
{
	std::cout << "center x: ";
	std::cin >> center.x;
	std::cout << "center y: ";
	std::cin >> center.y;

	std::cout << '\n';

	std::cout << "rad: ";
	std::cin >> rad;
}

void Circle::save(std::ofstream& out)
{
	out << "�� - �߽���(" << std::to_string(center.x) << "," << std::to_string(center.y)
		<< ") ������ " << std::to_string(rad) << '\n';
}

void Circle::load(std::ifstream& in)
{
	std::string str;
	char buf[100];
	in.getline(buf, 100, '(');
	in >> center.x;
	in.getline(buf, 100, ',');
	in >> center.y;
	while (in >> str) {
		if (str == "������")
			break;
	}
	in >> rad;
}
