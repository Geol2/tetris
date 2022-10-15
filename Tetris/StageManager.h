#pragma once

#include "value.h"
#include "MACRO.h"

class CStageManager
{

private:
	CStageManager();
	~CStageManager();

	static CStageManager* m_pInst;

	class CStage* m_pCurStage;

public:
	static CStageManager* GetInst() {
		// 싱글턴 구현
		if ( !m_pInst ) {
			m_pInst = new CStageManager;
		}
		return m_pInst;
	}

	static void DestroyInst() {
		SAFE_DELETE(m_pInst);
	}

	bool Init();
	void Run();
};

