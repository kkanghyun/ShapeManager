//-----------------------------------------------------------------------------
// 중심점의 좌표와 반지름으로 원을 정의할 수 있다.
// (다른 방식으로 원을 정의할 수도 있다)
//-----------------------------------------------------------------------------
#pragma once

#include "point.h"
#include "shape.h"

// 헤더에서는 위의 두 include 대신에 다음과 같이 전방선언(forward declaration)을 할 수도 있다
// struct Point;
// class Shape;

class Circle : public Shape {
	Point center;							// 중심점의 좌표
	double rad;								// 반지름

public:
	Circle();
	Circle(const Point& c, double r);
	Circle(const Circle& other);			// 깊은 복사를 할 필요가 없다면 프로그래머가 복사생성자를
											// 프로그램할 필요는 없다.
											// 만약 어떤 이유로 프로그램해야 한다면 메모리를 이해하고
											// 코딩해야 한다

	// 위 설명을 다음 줄과 같이 선언하여 대체할 수 있다
	// Circle(const Circle&) = default;
	~Circle();								// 소멸자를 프로그램할 필요가 없다는 것을 생각해 보자

	virtual void draw() const override;
	virtual void insertPoint() override;
	virtual void save(std::ofstream& out);
	virtual void load(std::ifstream& in);
};

