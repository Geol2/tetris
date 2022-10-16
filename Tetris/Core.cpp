#include "Core.h"
#include "StageManager.h"
#include "CShapeManager.h"

CCore* CCore::m_pInst = NULL;

CCore::CCore() {
	srand( (unsigned int)time(0) );
}

CCore::~CCore() {
	CShapeManager::DestroyInst(); 
	CStageManager::DestroyInst();
}

bool CCore::Init() {
	// 콘솔창 핸들 생성
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE) {
		return false;
	}

	// 스테이지 초기화
	if (!CStageManager::GetInst()->Init()){
		return false;
	}

	return true;
}

void CCore::SetConsolePos(SHORT x, SHORT y) {
	COORD pos = {x * 2, y};
	SetConsoleCursorPosition(m_hConsole, pos);
}

void CCore::Run() {
	while (true) {
		system("cls");
		CShapeManager::GetInst()->Update();
		
		CStageManager::GetInst()->Run();
		CShapeManager::GetInst()->Render();

		Sleep(1000);
	}
	//SetConsolePos(2, 3);

	//cout << "TEST" << endl;
}