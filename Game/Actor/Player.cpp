#include "Player.h"
#include "Engine.h"

Player::Player(const Vector2& position) 
	: Actor('P', Color::Green, position)
{
	// 그릴 때 사용할 정렬 순서 설정
	SetSortingOrder(3);
}

void Player::Tick(float deltaTime)
{
	//Actor::Tick(deltaTime);
	super::Tick(deltaTime);

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().Quit();
		return;
	}

	// 입력처리 해야 함
	if (Engine::Get().GetKeyDown(VK_RIGHT))
	{
		Vector2 position = Position();
		position.x += 1;
		SetPosition(position);
	}
	if (Engine::Get().GetKeyDown(VK_LEFT))
	{
		Vector2 position = Position();
		position.x -= 1;
		SetPosition(position);
	}
	if (Engine::Get().GetKeyDown(VK_UP))
	{
		Vector2 position = Position();
		position.y -= 1;
		SetPosition(position);
	}
	if (Engine::Get().GetKeyDown(VK_DOWN))
	{
		Vector2 position = Position();
		position.y += 1;
		SetPosition(position);
	}
}
