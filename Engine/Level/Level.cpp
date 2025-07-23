#include "Level.h"
#include "Actor/Actor.h"

Level::Level()
{

}
Level::~Level()
{

}

// ������ ���͸� �߰��� �� ���
void Level::AddActor(Actor* newActor)
{
	// ����ó��(�ߺ� ���� Ȯ��) �ʿ�

	// push_back / emplace_back : �迭 �� �ڿ� ���ο� �׸� �߰��ϴ� �Լ�
	actors.emplace_back(newActor);
	//actors.push_back(newActor);
}

// �̺�Ʈ �Լ�

// ��ü �����ֱ�(Lifetime)�� 1���� ȣ��� (�ʱ�ȭ ����)
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

// ������ ���� ȣ�� (�ݺ��� �۾� / ���Ӽ��� �ʿ��� �۾�)
void Level::Tick(float deltaTime)
{
	for (Actor* const actor : actors)
	{
		actor->Tick(deltaTime);
	}
}

// �׸��� �Լ�
void Level::Render()
{
	for (Actor* const actor : actors)
	{
		actor->Render();
	}
}