#pragma once

#include "ShapeManager.h"

enum class EMenu_Main { NONE, INSERT, DELETE, DRAW, EXIT };
enum class EMenu_Insert { NONE, TRIANGLE, RECTANGLE, CIRCLE, BACK };
enum class EMenu_Erase { NONE, TRIANGLE, RECTANGLE, CIRCLE, NUM, BACK };

class Engine {
	bool m_enable;
	ShapeManager* m_shapeManager;

public:
	Engine();
	~Engine();

	bool init();
	void run();

private:
	void insertMenu();
	void eraseMenu();

	void printMenu_Main();
	void printMenu_Insert();
	void printMenu_Erase();
	void printExit();
	EMenu_Main inputMenu_Main();
	EMenu_Insert inputMenu_Insert();
	EMenu_Erase inputMenu_Erase();
	int inputMenu_EraseNum();

	template <class T>
	void insertShape() {
		T* shape = new T;
		shape->insertPoint();
		m_shapeManager->insert(shape);
	}
};

