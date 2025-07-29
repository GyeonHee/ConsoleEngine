#pragma once

#include "Level/Level.h"
#include "Interface/ICanPlayerMove.h"

class SokobanLevel : public Level, public ICanPlayerMove
{
	RTTI_DECLARATIONS(SokobanLevel, Level)
public:
	SokobanLevel();

	// ICanPlayerMove��(��) ���� ��ӵ�
	virtual bool CanPlayerMove(
		const Vector2& playerPosition,
		const Vector2& newPosition
	) override;

private:
	// �� ������ �о ���� ��ü �����ϴ� �Լ�
	void ReadMapFile(const char* fileName);

	// ���� Ŭ���� Ȯ���ϴ� �Լ�
	bool CheckGameClear();

private:
	// ���� Ŭ��� ���� ����
	int targetScore = 0;

	// ���� Ŭ���� ���� Ȯ�� ����
	bool isGameClear = false;
};