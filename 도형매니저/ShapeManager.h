//-----------------------------------------------------------------------------
// ���� ���� ������ �����ϴ� Ŭ����
//-----------------------------------------------------------------------------
// Shape* (�θ� Ŭ������ *)�� ��ü ������ �����ϴ� ���� �ٽ�
//-----------------------------------------------------------------------------
#pragma once

#include "shape.h"

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
	bool erase(int idx);

	template <class T>
	int erase() {
		Shape** newShapes{ new Shape * [capacity] };
		int idx{};
		int cnt{};
		for (int i = 0; i < nShape; ++i) {
			if (dynamic_cast<T*>(shapes[i])) {
				delete shapes[i];
				++cnt;
			}
			else {
				newShapes[idx] = shapes[i];
				++idx;
			}
		}

		if (cnt == 0) {
			delete[] newShapes;
			return cnt;
		}

		delete[] shapes;
		nShape -= cnt;
		shapes = newShapes;

		return cnt;
	}

	void draw() const;					// ��ü ������ �׸��� �Լ�
	void clearShapes();

	int getShapeCount() const;
};

