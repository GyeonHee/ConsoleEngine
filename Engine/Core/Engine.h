#pragma once
#include "Core.h"
#include <Windows.h>

/*
* Todo: 2025�� 7�� 23�� �۾��� ��
  - Ű �Է� ���� (KeyState �迭)
  - Entity �߰� (Actor)
  - �̺�Ʈ �Լ� �߰� (BeginPlay, Tick, Render)
  - Level �߰� (���� ������ ��ġ�� ��ü(Actor) ���� ��ü)
*/

class Level;
class Engine_API Engine
{
	// Ű �Է� Ȯ���� ���� ����ü
	struct KeyState
	{
		// ���� �����ӿ� Ű�� ���ȴ��� ����
		bool isKeyDown = false;
		// ���� �����ӿ� Ű�� ���ȴ��� ����
		bool previousKeyDown = false;
	};
public:
	Engine();
	~Engine();

	// ���� ���� �Լ�
	void Run();
	
	// ���� �߰� �Լ�
	void AddLevel(Level* newLevel);

	// Ű Ȯ�� �Լ�
	bool GetKey(int keyCode);
	bool GetKeyDown(int keyCode);
	bool GetKeyUp(int keyCode);

	// ���� �Լ�
	void Quit();

private:
	void ProcessInput();

	void BeginPlay();
	void Tick(float deltaTime = 0.0f);
	void Render();

private:
	// ���� ���� �÷���
	bool isQuit = false;

	// Ű �Է� ���� ���� ����
	KeyState keyStates[255] = {};

	// ���� ����
	Level* mainLevel = nullptr;
};