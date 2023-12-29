//-----------------------------------------------------------------------------
// class Shape - Virtual Base Class
// �� Ŭ������ �߻� Ŭ����(abstract class)�̴�.
//-----------------------------------------------------------------------------
#pragma once

enum class EShape { CIRCLE, TRIANGLE, RECTANGLE };

#include <fstream>

class Shape {
	EShape m_type{};

public:
	Shape() {};
	virtual ~Shape() {};

	virtual void draw() const = 0;			// pure virtual function
	virtual void insertPoint() {};

	virtual void save(std::ofstream& out) {};
	virtual void load(std::ifstream& in) {};

	void setType(EShape type) {
		m_type = type;
	}
	EShape getType() const {
		return m_type;
	}
};