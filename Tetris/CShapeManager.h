#pragma once

#include "value.h"

class CShapeManager
{
private:
	CShapeManager();
	~CShapeManager();

	static CShapeManager* m_pInst;

	class CStage* m_pCurStage;

	// �ٴ��� ������ ǥ��
	list<class CShape*> m_ShapeList;

	// ���� �����ִ� ������ ǥ��
	class CShape* m_pCurShape;

	// ������ ���� ������ ǥ��
	class CShape* m_pNextShape;

	class CShape* CreateShape(SHAPE_TYPE eType);
	class CShape* CreateRandomShape();

public:
	static CShapeManager* GetInst() {
		// �̱��� ����
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