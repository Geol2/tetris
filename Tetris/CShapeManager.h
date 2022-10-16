#pragma once

#include "value.h"

class CShapeManager
{
private:
	CShapeManager();
	~CShapeManager();

	static CShapeManager* m_pInst;

	class CStage* m_pCurStage;

	// 바닥의 도형을 표현
	list<class CShape*> m_ShapeList;

	// 현재 나오있는 도형을 표현
	class CShape* m_pCurShape;

	// 다음에 나올 도형을 표현
	class CShape* m_pNextShape;

	class CShape* CreateShape(SHAPE_TYPE eType);
	class CShape* CreateRandomShape();

public:
	static CShapeManager* GetInst() {
		// 싱글턴 구현
		if (!m_pInst) {
			m_pInst = new CShapeManager;
		}
		return m_pInst;
	}

	static void DestroyInst() {
		SAFE_DELETE(m_pInst);
	}

	void Update();
	void Render();
};