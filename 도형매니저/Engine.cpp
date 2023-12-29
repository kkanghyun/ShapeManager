#include "Engine.h"
#include <iostream>
#include <string>
#include <fstream>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "Line.h"

Engine::Engine() :
    m_enable{ false },
    // 1. 관리 클래스를 만듦		
    m_shapeManager{ new ShapeManager{20} } // 최대 20개의 도형을 관리함
{
}

Engine::~Engine()
{
    delete m_shapeManager;
}

bool Engine::init()
{	
    // 2. 도형들을 관리 클래스에 삽입함
    m_shapeManager->insert(new Triangle());
    m_shapeManager->insert(new Triangle(Point(0, 0), Point(1, 1), Point(2, 2)));
    m_shapeManager->insert(new Circle(Point(1.23, 4.56), 7.89));

    for (int i = 0; i < 10; ++i)
        m_shapeManager->insert(new Rectangle(Point(i, i + 1), Point(i * 2, i * 3)));

    // 새 도형 추가
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
            system("pause");
            continue;
        case EMenu_Main::INSERT:
            insertMenu();
            break;
        case EMenu_Main::DELETE:
            eraseMenu();
            break;
        case EMenu_Main::DRAW:
            // 3. 관리하고 있는 모든 도형을 그림
            m_shapeManager->draw();
            system("pause");
            break;
        case EMenu_Main::SAVE:
            save();
            system("pause");
            break;
        case EMenu_Main::LOAD:
            load();
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
        case EMenu_Insert::LINE:
            insertShape<Line>();
            break;
        case EMenu_Insert::BACK:
            enable = false;
            break;
        }
    }
}

void Engine::eraseMenu()
{
    bool enable{ true };
    while (enable) {
        system("cls");

        printMenu_Erase();
        EMenu_Erase input{ inputMenu_Erase() };

        std::string str{};
        int eraseCount{};

        switch (input) {
        case EMenu_Erase::NONE:
            system("pause");
            continue;
        case EMenu_Erase::TRIANGLE:
            str = "삼각형";
            eraseCount = m_shapeManager->erase<Triangle>();
            break;
        case EMenu_Erase::RECTANGLE:
            str = "사각형";
            eraseCount = m_shapeManager->erase<Rectangle>();
            break;
        case EMenu_Erase::CIRCLE:
            str = "원";
            eraseCount = m_shapeManager->erase<Circle>();
            break;
        case EMenu_Erase::LINE:
            str = "라인";
            eraseCount = m_shapeManager->erase<Line>();
            break;
        case EMenu_Erase::NUM:
        {
            int idx = inputMenu_EraseNum();
            if (idx != -1) {
                m_shapeManager->erase(idx);
                std::cout << idx << "번 도형이 성공적으로 제거되었습니다." << '\n';
            }
            system("pause");
        }
            break;
        case EMenu_Erase::BACK:
            enable = false;
            break;
        }

        if (not str.empty()) {
            if (eraseCount == 0) {
                std::cout << str << "이(가) 존재하지 않습니다." << '\n';
            }
            else {
                std::cout << eraseCount << "개의 " << str << "이 제거되었습니다." << '\n';
            }

            system("pause");
        }
    }
}

void Engine::printMenu_Main()
{
    std::cout << "-------------------------------------------" << '\n';
    std::cout << "Menu" << '\n';
    std::cout << "-------------------------------------------" << '\n';
    std::cout << '\n';

    std::cout << "1. 원하는 도형 추가" << '\n';
    std::cout << "2. 원하는 도형 제거" << '\n';
    std::cout << "3. 전체 도형을 그리기" << '\n';
    std::cout << "4. 파일에 저장하기" << '\n';
    std::cout << "5. 파일에서 읽어오기" << '\n';
    std::cout << "6. 프로그램 끝내기" << '\n';
}

void Engine::printMenu_Insert()
{
    std::cout << "-------------------------------------------" << '\n';
    std::cout << "원하는 도형 추가" << '\n';
    std::cout << "-------------------------------------------" << '\n';
    std::cout << '\n';

    std::cout << "1. 삼각형" << '\n';
    std::cout << "2. 사각형" << '\n';
    std::cout << "3. 원" << '\n';
    std::cout << "4. 라인" << '\n';
    std::cout << "5. 뒤로가기" << '\n';
}

void Engine::printMenu_Erase()
{
    std::cout << "-------------------------------------------" << '\n';
    std::cout << "원하는 도형 제거" << '\n';
    std::cout << "-------------------------------------------" << '\n';
    std::cout << '\n';

    std::cout << "1. 삼각형" << '\n';
    std::cout << "2. 사각형" << '\n';
    std::cout << "3. 원" << '\n';
    std::cout << "4. 라인" << '\n';
    std::cout << "5. 번호로 제거" << '\n';
    std::cout << "6. 뒤로가기" << '\n';
}

void Engine::printExit()
{
    std::cout << "-------------------------------------------" << '\n';
    std::cout << "프로그램을 종료합니다." << '\n';
    std::cout << "-------------------------------------------" << '\n';
    std::cout << '\n';
}

EMenu_Main Engine::inputMenu_Main()
{
    std::cout << "input: ";
    std::string str;
    std::cin >> str;

    std::cout << '\n';

    int input{};

    try {
        input = std::stoi(str);
    }
    catch (std::invalid_argument& e) {
        std::cout << "잘못된 입력입니다." << '\n';
        std::cout << "error: " << e.what() << '\n';
        return EMenu_Main::NONE;
    }
    catch (std::out_of_range& e) {
        std::cout << "변환할 수 있는 값을 초과하였습니다." << '\n';
        std::cout << "error: " << e.what() << '\n';
        return EMenu_Main::NONE;
    }

    if (input <= static_cast<int>(EMenu_Main::NONE) || input > static_cast<int>(EMenu_Main::EXIT)) {
        std::cout << "잘못된 입력입니다." << '\n';
        return EMenu_Main::NONE;
    }

    return static_cast<EMenu_Main>(input);
}

EMenu_Insert Engine::inputMenu_Insert()
{
    std::cout << "input: ";
    std::string str;
    std::cin >> str;

    std::cout << '\n';

    int input{};

    if (str.empty())
        return EMenu_Insert::NONE;

    try {
        input = std::stoi(str);
    }
    catch (std::invalid_argument& e) {
        std::cout << "잘못된 입력입니다." << '\n';
        std::cout << "error: " << e.what() << '\n';
        return EMenu_Insert::NONE;
    }
    catch (std::out_of_range& e) {
        std::cout << "변환할 수 있는 값을 초과하였습니다." << '\n';
        std::cout << "error: " << e.what() << '\n';
        return EMenu_Insert::NONE;
    }

    if (input <= static_cast<int>(EMenu_Insert::NONE) || input > static_cast<int>(EMenu_Insert::BACK)) {
        std::cout << "잘못된 입력입니다." << '\n';
        return EMenu_Insert::NONE;
    }

    return static_cast<EMenu_Insert>(input);
}

EMenu_Erase Engine::inputMenu_Erase()
{
    std::cout << "input: ";
    std::string str;
    std::cin >> str;

    std::cout << '\n';

    int input{};

    try {
        input = std::stoi(str);
    }
    catch (std::invalid_argument& e) {
        std::cout << "잘못된 입력입니다." << '\n';
        std::cout << "error: " << e.what() << '\n';
        return EMenu_Erase::NONE;
    }
    catch (std::out_of_range& e) {
        std::cout << "변환할 수 있는 값을 초과하였습니다." << '\n';
        std::cout << "error: " << e.what() << '\n';
        return EMenu_Erase::NONE;
    }

    if (input <= static_cast<int>(EMenu_Erase::NONE) || input > static_cast<int>(EMenu_Erase::BACK)) {
        std::cout << "잘못된 입력입니다." << '\n';
        return EMenu_Erase::NONE;
    }

    return static_cast<EMenu_Erase>(input);
}

int Engine::inputMenu_EraseNum()
{
    if (m_shapeManager->getShapeCount() == 0) {
        std::cout << "제거할 도형이 없습니다." << '\n';
        return -1;
    }

    std::cout << "0 ~ " << m_shapeManager->getShapeCount() - 1 << "번 사이의 번호를 입력해주세요" << '\n';
    std::cout << "몇 번째 도형을 제거하시겠습니까? - ";
    std::string str;
    std::cin >> str;

    std::cout << '\n';

    int input{};

    try {
        input = std::stoi(str);
    }
    catch (std::invalid_argument& e) {
        std::cout << "잘못된 입력입니다." << '\n';
        std::cout << "error: " << e.what() << '\n';
        return -1;
    }
    catch (std::out_of_range& e) {
        std::cout << "변환할 수 있는 값을 초과하였습니다." << '\n';
        std::cout << "error: " << e.what() << '\n';
        return -1;
    }

    if (input < 0 || input >= m_shapeManager->getShapeCount()) {
        std::cout << "잘못된 입력입니다." << '\n';
        return -1;
    }

    return input;
}

void Engine::save()
{
    std::ofstream out{ "도형 데이터.txt" };
    if (not out) {
        std::cout << "파일을 생성하지 못하였습니다." << '\n';
    }

    m_shapeManager->save(out);
}

void Engine::load()
{
    std::ifstream in{ "도형 데이터.txt" };
    if (not in) {
        std::cout << "파일이 존재하지 않습니다." << '\n';
    }

    m_shapeManager->load(in);
}
