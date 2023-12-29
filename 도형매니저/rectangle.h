//-----------------------------------------------------------------------------
// 대각선에 있는 점 2개로 사각형을 정의할 수 있다
//-----------------------------------------------------------------------------
#pragma once

#include "shape.h"
#include "point.h"

class Rectangle : public Shape {
	Point p1, p2;

public:
	Rectangle();
	Rectangle(const Point& a, const Point& b);
	Rectangle(const Rectangle& other);
	~Rectangle();

	virtual void draw() const override;
	virtual void insertPoint() override;
	virtual void save(std::ofstream& out);
	virtual void load(std::ifstream& in);
};

