#pragma once

#include "value.h"

class CStage
{

public:
	CStage();
	~CStage();

	bool Init();
	void Render();

private:
	friend class CStageManager;

	char m_Stage[STAGE_HEIGHT][STAGE_WIDTH];
};