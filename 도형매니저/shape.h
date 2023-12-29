//-----------------------------------------------------------------------------
// class Shape - Virtual Base Class
// 이 클래스는 추상 클래스(abstract class)이다.
//-----------------------------------------------------------------------------
#pragma once

enum class EShape { CIRCLE, TRIANGLE, RECTANGLE };

class Shape {
	EShape m_type;

public:
	Shape() {};
	virtual ~Shape() {};

	virtual void draw() const = 0;			// pure virtual function
	virtual void insertPoint() {};

	void setType(EShape type) {
		m_type = type;
	}
	EShape getType() const {
		return m_type;
	}
};