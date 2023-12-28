//-----------------------------------------------------------------------------
// ���� ���� ������ �����ϴ� Ŭ����
//-----------------------------------------------------------------------------
// Shape* (�θ� Ŭ������ *)�� ��ü ������ �����ϴ� ���� �ٽ�
//-----------------------------------------------------------------------------
#pragma once

#include "shape.h"

enum class EShape { CIRCLE, TRIANGLE, RECTANGLE };

class ShapeManager {
	int nShape;							// ���� ���� ���� ������ ����
	int capacity;						// Ȯ���� �޸𸮿� ���� �� �ִ� ������ �ִ� ����
	Shape** shapes;						// ������ �����͵��� ���� �� �ִ� �޸�

public:
	explicit ShapeManager(int n);		// ���� �� �ִ� ������ ������ �����ڿ� ����
										// explicit ������ �˾ƺ���
	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	void insert(Shape* a);				// ������ �߰��ϴ� �Լ�
	void draw() const;					// ��ü ������ �׸��� �Լ�
};

