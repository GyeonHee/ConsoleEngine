#include "TestActor.h"
#include <iostream>
#include "Engine.h"
#include <Windows.h>

TestActor::TestActor() : Actor('P', Color::Red)
{
}

void TestActor::Tick(float deltaTime)
{
	// Actor
	super::Tick(deltaTime);

	/*std::cout << "TestActor::Tick. FPS: " 
		<< (1.0f / deltaTime) 
		<< "\n";*/

	if (Engine::Get().GetKey(VK_RIGHT) && Position().x < 30)
	{
		Vector2 position = Position();
		position.x += 1;
		SetPosition(position);
	}
	if (Engine::Get().GetKey(VK_LEFT) && Position().x > 0)
	{
		Vector2 position = Position();
		position.x -= 1;
		SetPosition(position);
	}
	if (Engine::Get().GetKey(VK_DOWN) && Position().y < 10)
	{
		Vector2 position = Position();
		position.y += 1;
		SetPosition(position);
	}
	if (Engine::Get().GetKey(VK_UP) && Position().y > 0)
	{
		Vector2 position = Position();
		position.y -= 1;
		SetPosition(position);
	}

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().Quit();
	}
}
