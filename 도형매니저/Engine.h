#pragma once

#include "ShapeManager.h"

enum class EMenu_Main { NONE, INSERT, DRAW, EXIT };
enum class EMenu_Insert { NONE, TRIANGLE, RECTANGLE, CIRCLE, BACK };

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

	void printMenu_Main();
	void printMenu_Insert();
	void printExit();
	EMenu_Main inputMenu_Main();
	EMenu_Insert inputMenu_Insert();

	template <class T>
	void insertShape() {
		T* shape = new T;
		shape->insertPoint();
		m_shapeManager->insert(shape);
	}
};

