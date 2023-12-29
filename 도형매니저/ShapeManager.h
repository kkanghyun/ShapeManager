//-----------------------------------------------------------------------------
// 여러 개의 도형을 관리하는 클래스
//-----------------------------------------------------------------------------
// Shape* (부모 클래스의 *)로 전체 도형을 관리하는 것이 핵심
//-----------------------------------------------------------------------------
#pragma once

#include "shape.h"

class ShapeManager {
	int nShape;							// 현재 관리 중인 도형의 갯수
	int capacity;						// 확보한 메모리에 담을 수 있는 도형의 최대 개수
	Shape** shapes;						// 도형의 포인터들을 담을 수 있는 메모리

public:
	explicit ShapeManager(int n);		// 담을 수 있는 도형의 갯수를 생성자에 전달
										// explicit 사용법을 알아보자
	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	void insert(Shape* a);				// 도형을 추가하는 함수
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

	void draw() const;					// 전체 도형을 그리는 함수
	void clearShapes();

	int getShapeCount() const;
};

