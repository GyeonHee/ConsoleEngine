#include "Player.h"

Player::Player(const Vector2& position) 
	: Actor('P', Color::Green, position)
{

}

void Player::Tick(float deltaTime)
{
	//Actor::Tick(deltaTime);
	super::Tick(deltaTime);

	// Todo: �Է�ó�� �ؾ� ��
}
