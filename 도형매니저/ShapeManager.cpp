#include "ShapeManager.h"
#include <iostream>
#include <string>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
using namespace std;

ShapeManager::ShapeManager(int n)
{
	nShape = 0;							// 처음 만들어질 때는 관리하는 도형 갯수가 0임
	capacity = n;						// 최대 n개의 도형을 담을 수 있음
	shapes = new Shape*[capacity];
}

ShapeManager::~ShapeManager()
{
	// 모든 객체가 정확하게 삭제되는지 반드시 확인하여야 한다.
	for (int i = 0; i < nShape; ++i) {
		delete shapes[i];
	}
	delete[] shapes;					// 도형관리자가 관리하는 도형의 소멸자를 호출함
}

void ShapeManager::insert(Shape* a)
{
	if (nShape + 1 == capacity) {
		capacity *= 2;
		Shape** newShapes{ new Shape * [capacity] };
		for (int i = 0; i < nShape; ++i) {
			newShapes[i] = shapes[i];
		}

		delete[] shapes;
		shapes = newShapes;
	}

	shapes[nShape] = a;
	nShape++;
}

bool ShapeManager::erase(int idx)
{
	if (nShape <= 0)
		return false;

	if (idx < 0 || idx >= nShape)
		return false;

	delete shapes[idx];

	for (int i = idx; i < nShape - 1; ++i) {
		shapes[i] = shapes[i + 1];
	}

	--nShape;

	return true;
}

void ShapeManager::draw() const
{
	cout << "-------------------------------------------" << '\n';
	cout << "관리하는 모든 도형을 그립니다" << '\n';
	cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다" << '\n';
	cout << "모두 " << nShape << "개의 도형이 있습니다" << '\n';
	cout << "-------------------------------------------" << '\n' << '\n';

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "]  ";
		shapes[i]->draw();				// 다형성이 구현된다.
	}
	cout << '\n';

	cout << "-------------------------------------------" << '\n';
	cout << "그리기를 마칩니다" << '\n';
	cout << "-------------------------------------------" << '\n' << '\n';
}

void ShapeManager::clearShapes()
{
	for (int i = 0; i < nShape; ++i) {
		delete shapes[i];
	}
	delete[] shapes;

	nShape = 0;
}

void ShapeManager::save(std::ofstream& out)
{
	out << std::to_string(capacity) << '\n';
	out << std::to_string(nShape) << '\n';
	for (int i = 0; i < nShape; ++i) {
		shapes[i]->save(out);
	}
}

void ShapeManager::load(std::ifstream& in)
{
	clearShapes();

	std::string str;
	in >> str;
	capacity = stoi(str);
	in >> str;
	int size = stoi(str);

	shapes = new Shape * [capacity];

	for (int i = 0; i < size; ++i) {
		in >> str;
		if (str == "원") {
			Circle* circle = new Circle;
			circle->load(in);
			insert(circle);
		}
		else if (str == "삼각형") {
			Triangle* triangle = new Triangle;
			triangle->load(in);
			insert(triangle);
		}
		else if (str == "사각형") {
			Rectangle* rectangle = new Rectangle;
			rectangle->load(in);
			insert(rectangle);
		}
	}

	int a = 0;
}

int ShapeManager::getShapeCount() const
{
	return nShape;
}
