#include "ShapeManager.h"
#include <iostream>
#include <string>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
using namespace std;

ShapeManager::ShapeManager(int n)
{
	nShape = 0;							// ó�� ������� ���� �����ϴ� ���� ������ 0��
	capacity = n;						// �ִ� n���� ������ ���� �� ����
	shapes = new Shape*[capacity];
}

ShapeManager::~ShapeManager()
{
	// ��� ��ü�� ��Ȯ�ϰ� �����Ǵ��� �ݵ�� Ȯ���Ͽ��� �Ѵ�.
	for (int i = 0; i < nShape; ++i) {
		delete shapes[i];
	}
	delete[] shapes;					// ���������ڰ� �����ϴ� ������ �Ҹ��ڸ� ȣ����
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
	cout << "�����ϴ� ��� ������ �׸��ϴ�" << '\n';
	cout << "�ִ� " << capacity << "���� ������ ���� �� �ֽ��ϴ�" << '\n';
	cout << "��� " << nShape << "���� ������ �ֽ��ϴ�" << '\n';
	cout << "-------------------------------------------" << '\n' << '\n';

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "]  ";
		shapes[i]->draw();				// �������� �����ȴ�.
	}
	cout << '\n';

	cout << "-------------------------------------------" << '\n';
	cout << "�׸��⸦ ��Ĩ�ϴ�" << '\n';
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
		if (str == "��") {
			Circle* circle = new Circle;
			circle->load(in);
			insert(circle);
		}
		else if (str == "�ﰢ��") {
			Triangle* triangle = new Triangle;
			triangle->load(in);
			insert(triangle);
		}
		else if (str == "�簢��") {
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
