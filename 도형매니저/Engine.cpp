#include "Engine.h"
#include <iostream>
#include <string>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

Engine::Engine() :
    m_enable{ false },
    m_shapeManager{ new ShapeManager{100} }
{
}

Engine::~Engine()
{
    delete m_shapeManager;
}

bool Engine::init()
{
    // 1. ���� Ŭ������ ����
    ShapeManager sm(100);					// �ִ� 100���� ������ ������

    // 2. �������� ���� Ŭ������ ������
    m_shapeManager->insert(new Triangle());
    m_shapeManager->insert(new Triangle(Point(0, 0), Point(1, 1), Point(2, 2)));
    m_shapeManager->insert(new Circle(Point(1.23, 4.56), 7.89));

    for (int i = 0; i < 10; ++i)
        m_shapeManager->insert(new Rectangle(Point(i, i + 1), Point(i * 2, i * 3)));

    // �� ���� �߰�
    m_shapeManager->insert(new Triangle(Point(0, 0), Point(1, 1), Point(2, 2)));
    m_shapeManager->insert(new Circle(Point(1.23, 4.56), 7.89));
    m_shapeManager->insert(new Rectangle(Point(1.23, 4.56), Point(1.23, 4.56)));

    m_enable = true;

    return true;
}

void Engine::run()
{
    while (m_enable) {
        system("cls");

        printMenu_Main();
        EMenu_Main input{ inputMenu_Main() };

        switch (input) {
        case EMenu_Main::NONE:
            continue;
        case EMenu_Main::INSERT:
            insertMenu();
            break;
        case EMenu_Main::DRAW:
            // 3. �����ϰ� �ִ� ��� ������ �׸�
            m_shapeManager->draw();
            system("pause");
            break;
        case EMenu_Main::EXIT:
            printExit();
            m_enable = false;
            break;
        }
    }
}

void Engine::insertMenu()
{
    bool enable{ true };
    while (enable) {
        system("cls");

        printMenu_Insert();
        EMenu_Insert input{ inputMenu_Insert() };

        switch (input) {
        case EMenu_Insert::NONE:
            continue;
        case EMenu_Insert::TRIANGLE:
            insertShape<Triangle>();
            break;
        case EMenu_Insert::RECTANGLE:
            insertShape<Rectangle>();
            break;
        case EMenu_Insert::CIRCLE:
            insertShape<Circle>();
            break;
        case EMenu_Insert::BACK:
            enable = false;
            break;
        }
    }
}

void Engine::printMenu_Main()
{
    std::cout << "-------------------------------------------" << '\n';
    std::cout << "Menu" << '\n';
    std::cout << "-------------------------------------------" << '\n';
    std::cout << '\n';

    std::cout << "1. ���ϴ� ���� �߰�" << '\n';
    std::cout << "2. ��ü ������ �׸���" << '\n';
    std::cout << "3. ���α׷� ������" << '\n';
}

void Engine::printMenu_Insert()
{
    std::cout << "-------------------------------------------" << '\n';
    std::cout << "���ϴ� ���� �߰�" << '\n';
    std::cout << "-------------------------------------------" << '\n';
    std::cout << '\n';

    std::cout << "1. �ﰢ��" << '\n';
    std::cout << "2. �簢��" << '\n';
    std::cout << "3. ��" << '\n';
    std::cout << "4. �ڷΰ���" << '\n';
}

void Engine::printExit()
{
    std::cout << "-------------------------------------------" << '\n';
    std::cout << "���α׷��� �����մϴ�." << '\n';
    std::cout << "-------------------------------------------" << '\n';
    std::cout << '\n';
}

EMenu_Main Engine::inputMenu_Main()
{
    std::cout << "input: ";
    std::string str;
    std::cin >> str;

    std::cout << '\n';

    if (str.length() > 1)
        return EMenu_Main::NONE;

    int input{ std::stoi(str) };
    
    if (input <= static_cast<int>(EMenu_Main::NONE) || input > static_cast<int>(EMenu_Main::EXIT))
        return EMenu_Main::NONE;

    return static_cast<EMenu_Main>(input);
}

EMenu_Insert Engine::inputMenu_Insert()
{
    std::cout << "input: ";
    std::string str;
    std::cin >> str;

    std::cout << '\n';

    if (str.length() > 1)
        return EMenu_Insert::NONE;

    int input{ std::stoi(str) };

    if (input <= static_cast<int>(EMenu_Insert::NONE) || input > static_cast<int>(EMenu_Insert::BACK))
        return EMenu_Insert::NONE;

    return static_cast<EMenu_Insert>(input);
}
