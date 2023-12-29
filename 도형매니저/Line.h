#pragma once

#include "shape.h"
#include "point.h"

class Line : public Shape {
	Point p1, p2;

public:
	Line();
	Line(const Point& a, const Point& b);
	Line(const Line& other);
	~Line();

	virtual void draw() const override;
	virtual void insertPoint() override;
	virtual void save(std::ofstream& out);
	virtual void load(std::ifstream& in);
};

