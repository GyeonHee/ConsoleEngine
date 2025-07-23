#include "Level.h"
#include "Actor/Actor.h"

Level::Level()
{

}
Level::~Level()
{

}

// 레벨에 액터를 추가할 때 사용
void Level::AddActor(Actor* newActor)
{
	// 예외처리(중복 여부 확인) 필요

	// push_back / emplace_back : 배열 맨 뒤에 새로운 항목 추가하는 함수
	actors.emplace_back(newActor);
	//actors.push_back(newActor);
}

// 이벤트 함수

// 객체 생애주기(Lifetime)에 1번만 호출됨 (초기화 목적)
void Level::BeginPlay()
{
	for (Actor* const actor : actors)
	{
		if (actor->HasBeganPlay())
		{
			continue;
		}

		actor->BeginPlay();
	}
}

// 프레임 마다 호출 (반복성 작업 / 지속성이 필요한 작업)
void Level::Tick(float deltaTime)
{
	for (Actor* const actor : actors)
	{
		actor->Tick(deltaTime);
	}
}

// 그리기 함수
void Level::Render()
{
	for (Actor* const actor : actors)
	{
		actor->Render();
	}
}