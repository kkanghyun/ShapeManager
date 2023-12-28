//-----------------------------------------------------------------------------
// Point class declaration - 헤더 파일은 언제나 공개되어야 한다
// 2차원 좌표 (x,y)를 나타낸다
//-----------------------------------------------------------------------------
#pragma once

struct Point {									// struct - default public
	double x, y;

	Point();									// default constructor - 스페셜 함수
	Point(double a, double b);
	Point(const Point& other) = default;		// 복사생성자 - 사용자가 만들 필요 없다는 의미
};
