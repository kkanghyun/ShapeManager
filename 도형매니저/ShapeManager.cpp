#include "ShapeManager.h"
#include <iostream>
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
}

int ShapeManager::getShapeCount() const
{
	return nShape;
}
