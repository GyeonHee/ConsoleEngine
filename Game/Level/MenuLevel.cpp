#include "MenuLevel.h"
#include "Game/Game.h"
#include "Utils/Utils.h"
#include "Input.h"

#include <iostream>

MenuLevel::MenuLevel()
{
	// 메뉴 아이템 추가
	items.emplace_back(new MenuItem("Resume Game", []() { Game::Get().ToggleMenu(); }));

	items.emplace_back(new MenuItem("Quit Game", []() { Game::Get().Quit(); }));

	length = static_cast<int>(items.size());
}

MenuLevel::~MenuLevel()
{
	for (MenuItem* item : items)
	{
		SafeDelete(item);
	}

	items.clear();
}

void MenuLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// 입력 처리
	if (Input::Get().GetKeyDown(VK_UP))
	{
		currentIndex = (currentIndex - 1 + length) % length;
	}
	if (Input::Get().GetKeyDown(VK_DOWN))
	{
		currentIndex = (currentIndex + 1) % length;
	}
	// 엔터키 입력
	if (Input::Get().GetKeyDown(VK_RETURN))
	{
		items[currentIndex]->onSelected();
	}
	if (Input::Get().GetKeyDown(VK_ESCAPE))
	{
		Game::Get().ToggleMenu();
		currentIndex = 0;
	}

}

void MenuLevel::Render()
{
	super::Render();

	// 색상 & 좌표 정리
	Utils::SetCursorPosition({ 0,0 });
	Utils::SetConsoleTextColor(static_cast<WORD>(unselectedColor));

	std::cout << "SokobanGame\n\n";

	// 메뉴 아이템 랜더링
	for (int i = 0; i < length; ++i)
	{
		// 아이템 색상 확인
		Color textColor = (i == currentIndex) ? selectedColor : unselectedColor;

		// 메뉴 텍스트 출력
		Utils::SetConsoleTextColor(static_cast<WORD>(textColor));
		std::cout << items[i]->menuText << "\n";
	}
}
