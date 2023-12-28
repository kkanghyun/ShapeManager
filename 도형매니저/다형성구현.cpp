//-----------------------------------------------------------------------------
// 찾아보고 알아볼 것
// 
//		- 다형성(Ploymorphism)이란 무엇인가?
//		- C++ 언어에서는 어떻게 다형성을 구현하는가?
//-----------------------------------------------------------------------------
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Engine.h"

int main()
{
	// 메모리 릭 체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 이 프로그램은 프로젝트를 확인하기 위한 것이다.
	// 실습 순서대로 문제를 해결해 보자.
	Engine engine;
	if (not engine.init())
		return -1;

	engine.run();

	// 이 프로그램에서 잘못된 점을 찾을 수 있는가?
	// 잘못된 점을 어떻게 찾을 수 있는가?
}