#include "Player.h"
#include "Engine.h"

Player::Player(const Vector2& position) 
	: Actor('P', Color::Green, position)
{
	// �׸� �� ����� ���� ���� ����
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

	// �Է�ó�� �ؾ� ��
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
