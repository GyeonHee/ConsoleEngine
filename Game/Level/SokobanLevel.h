#pragma once

#include "Level/Level.h"
#include "Interface/ICanPlayerMove.h"

class SokobanLevel : public Level, public ICanPlayerMove
{
	RTTI_DECLARATIONS(SokobanLevel, Level)
public:
	SokobanLevel();

private:
	void ReadMapFile(const char* fileName);

	// ICanPlayerMove을(를) 통해 상속됨
	virtual bool CanPlayerMove(
		const Vector2& playerPosition,
		const Vector2& newPosition
	) override;
};