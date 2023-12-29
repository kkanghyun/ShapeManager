//-----------------------------------------------------------------------------
// 세 점으로 삼각형을 정의할 수 있다
//-----------------------------------------------------------------------------
#pragma once

#include "point.h"								// Point를 Triangle에서 사용
#include "shape.h"								// Shape을 상속 받음

class Triangle : public Shape {
	Point p1, p2, p3;

public:
	Triangle();
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle& other);
	~Triangle();

	virtual void draw() const override;			// virtual function을 overriding
	virtual void insertPoint() override;
	virtual void save(std::ofstream& out);
	virtual void load(std::ifstream& in);
};

